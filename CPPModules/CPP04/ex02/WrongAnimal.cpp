/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:49:17 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/19 16:42:06 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& ex)
{
	this->type = ex.type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ex)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;

	if (this != &ex)
	{
		this->type = ex.type;
	}

	return (*this);
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal desctructor called" << std::endl;
}
std::string WrongAnimal::getType() const
{
	return (this->type);
}
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a sound!" << std::endl;
}
	