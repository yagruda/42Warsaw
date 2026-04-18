/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:17:32 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/18 14:10:16 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat"; // we override the type member variable from the Animal class
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat& ex) : Animal(ex) // we call the copy constructor of the Animal class to copy the type member variable
{
	this->type = ex.type; // we copy the type member variable from the Cat class
	std::cout << "Cat copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& ex)
{
	std::cout << "Cat copy assignment operator called" << std::endl;

	if (this != &ex)
	{
		this->type = ex.type;
	}

	return (*this);
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat meows!" << std::endl;
}
