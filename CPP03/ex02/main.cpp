/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:09:34 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/18 12:37:23 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


int main()
{
    std::cout << "--- ClapTrap ---" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "-- ScavTrap ---" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("enemy");
    scav.guardGate();
    scav.takeDamage(10);

    std::cout << "--- FragTrap ---" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("enemy");
    frag.highFivesGuys();
    frag.takeDamage(20);

    std::cout << "--- Copy ---" << std::endl;
    FragTrap frag2(frag);
    frag2.highFivesGuys();

    std::cout << "--- Destructors ---" << std::endl;
    return 0;
}