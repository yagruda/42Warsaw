/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:09:29 by yhruda            #+#    #+#             */
/*   Updated: 2026/01/05 16:16:50 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// TBD: implement the ClapTrap class methods
ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "DefaultClapTrap";
	this->_hitpoints = 10;
	this->_energypoints = 10;
	this->_attackdamage = 0;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	// TBD ClapTrap <name> attacks <target>, causing <damage> points of damage!
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	// TBD
	return;
}

void beRepaired(unsigned int amount)
{
	// TBD
	return;
}