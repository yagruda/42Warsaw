import re
import urllib.parse
from typing import List, Tuple

import requests
import polyline
import gpxpy
import gpxpy.gpx


def _geocode(place: str) -> Tuple[float, float]:
    """Geocode a place name using Nominatim."""
    url = "https://nominatim.openstreetmap.org/search"
    params = {"q": place, "format": "json", "limit": 1}
    resp = requests.get(url, params=params, headers={"User-Agent": "polyline-to-gpx"})
    resp.raise_for_status()
    data = resp.json()
    if not data:
        raise ValueError(f"Could not geocode {place!r}")
    return float(data[0]["lat"]), float(data[0]["lon"])


def _osrm_route(origin: Tuple[float, float], dest: Tuple[float, float]) -> str:
    """Fetch route polyline from the OSRM demo server."""
    o_lat, o_lon = origin
    d_lat, d_lon = dest
    url = (
        f"http://router.project-osrm.org/route/v1/driving/"
        f"{o_lon},{o_lat};{d_lon},{d_lat}?overview=full&geometries=polyline"
    )
    resp = requests.get(url)
    resp.raise_for_status()
    data = resp.json()
    return data["routes"][0]["geometry"]


def _extract_polyline_from_html(html: str) -> str | None:
    """Try to pull an encoded polyline from a Google Maps HTML page."""
    m = re.search(r"polyline\\\":\\\"([^\\\"]+)", html)
    if m:
        return m.group(1)
    m = re.search(r"\"points\":\"([^\"]+)\"", html)
    if m:
        return m.group(1)
    return None


def google_maps_link_to_gpx(url: str) -> None:
    """Convert a Google Maps directions URL into a GPX file named route.gpx."""
    resp = requests.get(url)
    resp.raise_for_status()
    html = resp.text
    encoded = _extract_polyline_from_html(html)

    if not encoded:
        # fall back to using OSRM with geocoded start and end points
        path_parts = [p for p in urllib.parse.urlparse(url).path.split("/") if p]
        # after 'dir', the remainder are places
        try:
            idx = path_parts.index("dir")
            places = [urllib.parse.unquote(p) for p in path_parts[idx + 1 :]]
        except ValueError:
            places = []
        if len(places) < 2:
            raise ValueError("Could not determine origin and destination from URL")
        origin = _geocode(places[0])
        dest = _geocode(places[-1])
        encoded = _osrm_route(origin, dest)

    points: List[Tuple[float, float]] = polyline.decode(encoded)

    gpx = gpxpy.gpx.GPX()
    route = gpxpy.gpx.GPXRoute()
    for lat, lon in points:
        route.points.append(gpxpy.gpx.GPXRoutePoint(lat, lon))
    gpx.routes.append(route)

    with open("route.gpx", "w", encoding="utf-8") as f:
        f.write(gpx.to_xml())


if __name__ == "__main__":
    google_maps_link_to_gpx("https://www.google.com/maps/dir/Paris/Brussels/")
