/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:09:34 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/15 16:58:35 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main()
{
	int damage = 5;
	
	ClapTrap a("CL4P-TP");
	a.attack("CL-8");
	a.takeDamage(damage);
	a.beRepaired(damage);
	a.takeDamage(91);
	
	return 0;
}