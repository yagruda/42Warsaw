/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:04:19 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 15:15:22 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_HPP
#define Weapon_HPP

#include <iostream>

class Weapon
{
	public:
		std::string _type;
		
		Weapon();
		Weapon(std::string type);
		
		void setType(std::string);
		const std::string& getType(void); // return reference, not copy. Use CONST so it can't get changed by example obj.getType = "knife"; 
		
};

#include "HumanA.hpp"
#include "HumanB.hpp"

#endif