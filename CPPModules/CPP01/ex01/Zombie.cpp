/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:32:05 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 13:47:25 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(string name):_name(name)
{
	std::cout << this->_name << " is created" << std::endl;
}

Zombie::~Zombie()
{
	//delete this;
	std::cout << this->_name << " is killed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string newName)
{
	this->_name = newName;
}

Zombie::Zombie()
{
	// std::cout << "empty guy is created" << std::endl; FOR DEBUG ONLY
}