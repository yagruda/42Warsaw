/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:15:08 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 15:21:45 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon._type << std::endl;
}

// (name) is assigned to _name and (weapon) to _weapon
// HumanA takes weapon in it's constructor
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	
}