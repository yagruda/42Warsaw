/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:12:59 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/18 12:34:45 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default_FragTrap", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap parameterized constructor called for " << this->_name << std::endl;
}
FragTrap::FragTrap(const FragTrap& ex) : ClapTrap(ex)
{
	std::cout << "FragTrap copy constructor called" <<  std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& ex)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	// because FragTrap doesn't have its own member variables, we can just call the base class assignment operator to copy the inherited members
	// so we wouldn't make a mess 
	if (this != &ex)
		ClapTrap::operator=(ex); 
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is requesting a high five!" << std::endl;
}
