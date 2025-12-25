/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:32:05 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/23 18:22:45 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *Z = new Zombie[N]; // we create pointer to class Zombie *Z and allocate Zombie[N] memory for it.


	for (i = 0; i < N, i++;)
	{
		zombiesArr[i] = newZombie(name);
		(*zombiesArr[i]).announce();
	}

	return zombiesArr;
}

