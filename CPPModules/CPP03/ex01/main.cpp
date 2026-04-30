/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:09:34 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/18 12:15:44 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("CL4P-TP");
    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);

    ScavTrap scav("SC4V-TP");
    scav.attack("Psycho");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();
    
    
    return 0;
}