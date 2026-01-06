/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:09:32 by yhruda            #+#    #+#             */
/*   Updated: 2026/01/05 18:09:29 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

// TBD: check Is it Orthodox Canonical Form
class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hitpoints; // Health 
		unsigned int _energypoints;
		unsigned int _attackdamage;
		
		ClapTrap(std::string name, unsigned int hitpoints, unsigned int energypoints, unsigned int attackdamage); //can be called from the class itself and from derived classes, but not from external code
		
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& ex);
		ClapTrap &operator=(const ClapTrap& ex);
		~ClapTrap();
		
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
};

#endif