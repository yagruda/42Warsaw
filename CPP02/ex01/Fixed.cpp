/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:15:32 by yhruda            #+#    #+#             */
/*   Updated: 2026/01/03 13:09:07 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
◦ A member function int getRawBits( void ) const;
that returns the raw value of the fixed-point value.
◦ A member function void setRawBits( int const raw );
that sets the raw value of the fixed-point number.
*/

#include "Fixed.hpp"

Fixed::Fixed(void) : _fipnum(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : _fipnum(num << _frbits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _fipnum(roundf(num * (1 << _frbits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ex) : _fipnum(ex._fipnum)
{
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Fixed &Fixed::operator=(const Fixed& ex)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fipnum = ex._fipnum;
	return(*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fipnum;
}
void Fixed::setRawBits(int const raw)
{
	this->_fipnum = raw;
	std::cout << "setRawBits member function called" << std::endl;
	
}
// Shifting the bits of a float would corrupt the exponent and sign bits, resulting in a nonsensical value rather than a mathematically scaled number.
float Fixed::toFloat (void) const
{
	return (float)this->_fipnum / (1 << this->_frbits); 
}
// shifting right by 8 bits is equivalent to dividing by 256
int Fixed::toInt (void) const
{
	return this->_fipnum >> this->_frbits; 
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}