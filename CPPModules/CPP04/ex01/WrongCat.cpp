/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:50:13 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/18 14:54:50 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat"; // we override the type member variable from the WrongAnimal class
	std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& ex) : WrongAnimal(ex) // we call the copy constructor of the WrongAnimal class to copy the type member variable
{
	this->type = ex.type; // we copy the type member variable from the WrongCat class
	std::cout << "WrongCat copy constructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& ex)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;

	if (this != &ex)
	{
		this->type = ex.type;
	}

	return (*this);
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}
void WrongCat::makeSound() const
{
	std::cout << "WrongCat meows!" << std::endl;
}
