#include "vect2.hpp"

vect2& vect2::operator=(const vect2& source)
{
	if (this != &source)
	{
		this->x = source.x;
		this->y = source.y;
	}
	return (*this);
}

vect2::vect2(const vect2& source)
{
	*this = source;
}

vect2::~vect2()
{
	
}

int& vect2::operator[](int i) 
{
  if (i == 0)
    return this->x;
  else
    return this->y;
}

int vect2::operator[](int i) const
{
	if (i == 0)
	{
		return (this->x);
	}
	else
		return (this->y);
}

vect2 vect2::operator++(int)
{
  vect2 temp = *this;
  this->y++;
  this->x++;

  return temp;
}

vect2& vect2::operator++()
{
  this->y++;
  this->x++;

  return *this;
}


vect2 vect2::operator--(int)
{
  vect2 temp = *this;
  this->y--;
  this->x--;

  return temp;
}

vect2& vect2::operator--()
{
  this->y--;
  this->x--;

  return *this;
}

vect2& vect2::operator+=(const vect2& obj)
{
  this->x += obj.x;
  this->y += obj.y;

  return *this;
}

vect2& vect2::operator-=(const vect2& obj)
{
  this->x -= obj.x;
  this->y -= obj.y;

  return *this;
}

vect2 vect2::operator+(const vect2& obj) const
{
  vect2 result;
  result.x = this->x + obj.x;
  result.y = this->y + obj.y;

  return result;
}

vect2 vect2::operator-(const vect2& obj) const
{
  vect2 result;
  result.x = this->x - obj.x;
  result.y = this->y - obj.y;

  return result;
}

vect2 vect2::operator-()
{
  vect2 result = *this;
  result.x = -this->x;
  result.y = -this->y;
  return result;
}

vect2 vect2::operator*(int num)const
{
  vect2 result;
  result.x = this->x * num;
  result.y = this->y * num;
  return result;
}

vect2& vect2::operator*=(int num)
{
  this->x *= num;
  this->y *= num;

  return *this;
}



vect2 operator*(int num, const vect2& obj)
{
  vect2 result(obj);
  result *= num;
  return result;
}

bool vect2::operator==(const vect2& obj) const
{
  if ((this->x == obj.x) && (this->y == obj.y))
    return true;
  else
    return false;
}

bool vect2::operator!=(const vect2& obj) const
{
  if ((this->x == obj.x) && (this->y == obj.y))
    return false;
  else
    return true;
}

std::ostream& operator<<(std::ostream& os, const vect2& obj)
{
	std::cout << "{" << obj[0] << ", " << obj[1] << "}";
	return(os);
}


