/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:09:29 by yhruda            #+#    #+#             */
/*   Updated: 2026/01/05 18:16:15 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitpoints(10), _energypoints(10), _attackdamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "DefaultClapTrap";
}
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitpoints(10), _energypoints(10), _attackdamage(0)
{
	std::cout << "ClapTrap parameterized constructor called for " << this->_name << std::endl;
}
ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int energy, unsigned int damage) : _name(name), _hitpoints(hp), _energypoints(energy), _attackdamage(damage)
{
	std::cout << "ClapTrap parameterized constructor called for " << this->_name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ex)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &ex)
	{
		this->_name = ex._name;
		this->_hitpoints = ex._hitpoints;
		this->_energypoints = ex._energypoints;
		this->_attackdamage = ex._attackdamage;
	}
	return (*this);
}

// The assignment operator copies all member variables from ex into *this
ClapTrap::ClapTrap(const ClapTrap& ex) : _name(ex._name), _hitpoints(ex._hitpoints), _energypoints(ex._energypoints), _attackdamage(ex._attackdamage)
{
	std::cout << "ClapTrap copy constructor called" <<  std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	if (this->_energypoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdamage << " points of damage!" << std::endl;
		this->_energypoints -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points left to attack!" << std::endl;
	}
	return;
}

// Subject isn't clear about it
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
	else
	{
		this->_hitpoints -= amount;
		if (this->_hitpoints <= 0)
			std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage and is now dead!" << std::endl;
		else
			std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage and has " << this->_hitpoints << " hitpoints left!" << std::endl;
		}
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_energypoints -= 1;
	this->_hitpoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << " points and now has " << this->_hitpoints << " hitpoints!" << std::endl;
	return;
}