/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:47:15 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 13:47:27 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Time to create a horde of Zombies!
Implement the following function in the appropriate file:
Zombie* zombieHorde( int N, std::string name );
It must allocate N Zombie objects in a single allocation. Then, it must initialize the
zombies, giving each of them the name passed as a parameter. The function returns a
pointer to the first zombie.
Implement your own tests to ensure that your zombieHorde() function works as ex-
pected. Try calling announce() for each of the zombies.
Do not forget to use delete to deallocate all the zombies and check for memory
leaks.
*/

#include "Zombie.hpp"


int main()
{
	Zombie* zombiesArr = zombieHorde(5, "Vasya");
	
	for (int i = 0; i < 5; i++)
	{
		zombiesArr[i].announce();
	}

	delete[] zombiesArr;

	return 0;
}