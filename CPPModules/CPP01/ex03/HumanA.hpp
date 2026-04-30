/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:03:04 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 15:38:18 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_hpp
#define HumanA_HPP

class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon; // reference ensures _weapon isn't NULL
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack(void);
		
};

#endif