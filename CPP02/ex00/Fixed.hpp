/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:15:34 by yhruda            #+#    #+#             */
/*   Updated: 2026/01/02 19:54:42 by yhruda           ###   ########.fr       */
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

class Fixed
{
	private:
		int _fipnum; // fixed-point number a.k a raw number
		static const int _frbits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& ex);
		Fixed &operator=(const Fixed& ex);
		~Fixed(void);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
};

#endif