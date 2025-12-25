/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:32:10 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/23 18:15:41 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
#define Zombie_HPP

#include <string>
#include <iostream>

typedef std::string string;

class Zombie {
	private:
		string _name;
	public:
		~Zombie();
		Zombie(string name);
		Zombie();
		void announce(void);
};
	
Zombie* newZombie(string name); // dynamic (heap) memory allocation
void randomChump(string name); // put on stack, call announce
Zombie* zombieHorde( int N, std::string name ); //ex01

#endif