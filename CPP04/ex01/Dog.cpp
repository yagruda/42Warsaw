/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:17:31 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/19 15:05:45 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog"; // we override the type member variable from the Animal class
	this->brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog& ex) : Animal(ex) // we call the copy constructor of the Animal class to copy the type member variable
{
	this->type = ex.type; // we copy the type member variable from the Dog class
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& ex)
{
	std::cout << "Dog copy assignment operator called" << std::endl;

	if (this != &ex)
	{
		this->type = ex.type;
	}

	return (*this);
}
Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog barks!" << std::endl;
}

