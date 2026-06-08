#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_container = other._container;
	}
	return *this;
}

Span::~Span() {}

long int Span::shortestSpan() const
{
	if (_container.size() < 2)
		throw std::runtime_error("Not enough elements to find a span.");

	std::vector<int> sortedContainer = _container;
	std::sort(sortedContainer.begin(), sortedContainer.end());

	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedContainer.size(); ++i)
	{
		int span = sortedContainer[i] - sortedContainer[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

long int Span::longestSpan() const
{
	if (_container.size() < 2)
		throw std::runtime_error("Not enough elements to find a span.");

	int min = *std::min_element(_container.begin(), _container.end());
	int max = *std::max_element(_container.begin(), _container.end());

	std::cout << "Longest Span: " << (max - min) << std::endl;

	return max - min;
}

void Span::addNumber(int number)
{
	if (_container.size() >= _N)
		throw std::runtime_error("Cannot add more numbers, container is full.");
	_container.push_back(number);
}