/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:32:13 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/23 18:24:30 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *Zombik;

	Zombik = newZombie("Dinazaur");
	(*Zombik).announce();
	delete Zombik;
	
	randomChump("Zalupa");
	
	return 0;
}