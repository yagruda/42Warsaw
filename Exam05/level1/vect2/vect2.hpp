#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 
{
	private:
		int x;
		int y;
	public:
		vect2() : x(0), y(0) {};
		vect2(int num1, int num2) : x(num1), y(num2) {};
		vect2(const vect2& source);
		vect2& operator=(const vect2& source);

		int operator[](int i) const;
		int& operator[](int i);

		vect2 operator-() const;
		vect2 operator*(int num)const;

		vect2& operator*=(int num);

		vect2& operator+=(const vect2& obj);
		vect2& operator-=(const vect2& obj);
		vect2& operator*=(const vect2& obj);

		vect2 operator+(const vect2& obj) const;
		vect2 operator-(const vect2& obj) const;
		vect2 operator*(const vect2& obj) const;

		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

		bool operator==(const vect2& obj) const;
		bool operator!=(const vect2& obj) const;

		vect2 operator-();
		
		~vect2();
};

vect2 operator*(int num, const vect2& obj);
std::ostream& operator<<(std::ostream& os, const vect2& obj);

#endif