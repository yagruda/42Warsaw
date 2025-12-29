/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:00:49 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 15:14:38 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	
}
Weapon::Weapon()
{
	
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string& Weapon::getType(void)
{
	return this->_type;
}

