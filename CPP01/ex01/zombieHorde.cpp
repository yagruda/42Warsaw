/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:32:05 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 13:47:25 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombiesArr = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombiesArr[i].setName(name);
	}

	return zombiesArr;
}

