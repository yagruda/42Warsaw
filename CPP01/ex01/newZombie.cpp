/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:50:59 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/23 18:17:51 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
This function creates a zombie, names it, and returns it so you can use it outside
of the function scope
*/

Zombie* newZombie(string name)
{
	Zombie *zombik;
	zombik = new Zombie(name);
	
	
	return zombik;
}