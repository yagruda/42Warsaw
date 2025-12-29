/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:04:19 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 14:43:32 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_HPP
#define Weapon_HPP

#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		std::string getType();
		void setType(std::string);
		
};

#include "HumanA.hpp"
#include "HumanB.hpp"

#endif