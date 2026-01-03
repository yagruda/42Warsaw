/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:15:34 by yhruda            #+#    #+#             */
/*   Updated: 2026/01/03 12:34:17 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Private members:
◦ An integer to store the fixed-point number value.
◦ A static constant integer to store the number of fractional bits. Its value
will always be the integer literal 8.
• Public members:
◦ A default constructor that initializes the fixed-point number value to 0.
◦ A copy constructor.
◦ A copy assignment operator overload.
◦ A destructor.
*/


// raw value - actual integer. 
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fipnum; // fixed-point number a.k a raw value like 640
		static const int _frbits = 8;
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& ex);
		Fixed &operator=(const Fixed& ex);
		~Fixed(void);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat (void) const;
		int toInt (void) const;
		
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif