/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:32:10 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 14:16:26 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
#define Zombie_HPP

#include <string>
#include <iostream>
#include 

typedef std::string string;

class Zombie {
	private:
		string _name;
	public:
		~Zombie();
		Zombie(string name);
		Zombie();
		void announce(void);
		void setName(std::string newName);
};
	

Zombie* zombieHorde( int N, std::string name ); //ex01

#endif