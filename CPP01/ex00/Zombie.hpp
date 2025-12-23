/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:32:10 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/16 17:04:34 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
#define Zombie_HPP

#include <string>
#include <iostream>

typedef std::string string;

class Zombie {
	private:
		string name;
	public:
		void announce(void);
		Zombie* newZombie(string name);
		void randomChump(string name); 
		~Zombie();
};

#endif