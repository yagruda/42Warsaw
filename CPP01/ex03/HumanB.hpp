/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:03:41 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 14:43:02 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_hpp
#define HumanB_hpp

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		void attack(void);
		HumanB(Weapon);
		HumanB();
		
};

#endif