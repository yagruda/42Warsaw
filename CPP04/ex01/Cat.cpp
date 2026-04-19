/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:17:32 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/19 15:29:28 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat"; // we override the type member variable from the Animal class
	this->brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat& ex) : Animal(ex), brain(new Brain(*ex.brain))
{
    this->type = ex.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& ex)
{
    if (this != &ex)
    {
        this->type = ex.type;
        delete this->brain;
        this->brain = new Brain(*ex.brain);
    }
    return (*this);
}
Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat meows!" << std::endl;
}

void Cat::giveIdea(int index)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Invalid index for ideas" << std::endl;
		return;
	}
	std::cout << "Cat's idea: " << this->brain->ideas[index] << std::endl;
}