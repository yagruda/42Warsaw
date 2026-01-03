/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:15:31 by yhruda            #+#    #+#             */
/*   Updated: 2026/01/03 13:09:23 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a(5.1f);
	Fixed b(5);

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << "test " << (5<<8) << std::endl;

	return 0;
}