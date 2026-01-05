/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:09:34 by yhruda            #+#    #+#             */
/*   Updated: 2026/01/05 18:14:41 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Test 1: Basic ClapTrap ===" << std::endl;
    ClapTrap clap("CL4P-TP");
    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);
    std::cout << std::endl;

    std::cout << "=== Test 2: Basic ScavTrap ===" << std::endl;
    ScavTrap scav("SC4V-TP");
    scav.attack("Psycho");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
    std::cout << std::endl;

    std::cout << "=== Test 3: Construction/Destruction Order ===" << std::endl;
    {
        ScavTrap temp("Temporary");
    }
    std::cout << std::endl;

    std::cout << "=== Test 4: Copy Constructor ===" << std::endl;
    ScavTrap original("Original");
    ScavTrap copy(original);
    copy.attack("Target");
    std::cout << std::endl;

    std::cout << "=== Test 5: Assignment Operator ===" << std::endl;
    ScavTrap a("ScavA");
    ScavTrap b("ScavB");
    b = a;
    b.guardGate();
    std::cout << std::endl;

    std::cout << "=== Test 6: Multiple Attacks ===" << std::endl;
    ScavTrap fighter("Fighter");
    for (int i = 0; i < 3; i++)
        fighter.attack("Enemy");
    std::cout << std::endl;

    std::cout << "=== End of tests - destructors will be called ===" << std::endl;
    return 0;
}