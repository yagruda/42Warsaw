/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:17:31 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/19 15:29:20 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog"; // we override the type member variable from the Animal class
	this->brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog& ex) : Animal(ex), brain(new Brain(*ex.brain))
{
    this->type = ex.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& ex)
{
    if (this != &ex)
    {
        this->type = ex.type;
        delete this->brain;
        this->brain = new Brain(*ex.brain);
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

