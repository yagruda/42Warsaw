/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:03:41 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 15:38:19 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_hpp
#define HumanB_hpp

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon; // *pointer allows _weapon to be NULL 
	public:
		HumanB(std::string name);
		void attack(void);
		void setWeapon(Weapon& weapon);
	
		
};

#endif