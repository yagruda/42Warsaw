/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:23:43 by yhruda            #+#    #+#             */
/*   Updated: 2026/01/05 18:08:03 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_ScavTrap", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap parameterized constructor called for " << this->_name << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& ex) : ClapTrap(ex)
{
	std::cout << "ScavTrap copy constructor called" <<  std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& ex)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &ex)
	{
		this->_name = ex._name;
		this->_hitpoints = ex._hitpoints;
		this->_energypoints = ex._energypoints;
		this->_attackdamage = ex._attackdamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energypoints > 0 && this->_hitpoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdamage << " points of damage!" << std::endl;
		this->_energypoints -= 1;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " has no energy points left to attack!" << std::endl;
	}
	return;
}