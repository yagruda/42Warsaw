/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:15:23 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/19 16:29:21 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(const Animal& ex)
{
	*this = ex;
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal& Animal::operator=(const Animal& ex)
{
	std::cout << "Animal copy assignment operator called" << std::endl;

	if (this != &ex)
	{
		this->type = ex.type;
	}

	return (*this);
}
Animal::~Animal()
{
	std::cout << "Animal desctructor called" << std::endl;
}
std::string Animal::getType() const
{
	return (this->type);
}
void Animal::makeSound() const
{
	std::cout << "Animal makes a sound!" << std::endl;
}
