/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:09:34 by yhruda            #+#    #+#             */
/*   Updated: 2026/01/05 17:01:31 by yhruda           ###   ########.fr       */
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
	
	return 0;
}