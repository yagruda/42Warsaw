/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:59:06 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/04 18:00:24 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Make back-end first and then polish to make beautiful (as required)


#include "global.hpp"

	// // SEARCH
	// if (firstObj.first_name.length() > 10)
	// 	std::cout.write(firstObj.first_name.c_str(), 10) << '.' << std::endl;
	// else
	// 	std::cout << firstObj.first_name;

int main()
{	
	PhoneBook PhoneBookObj;	
	
	int ci = 0;

	while (1)
	{
		
		string uinput;
		std::cin >> uinput;

		if (!(uinput.compare("ADD")))
		{
			if (ci == 9)
				ci = 0;
			
			PhoneBookObj.addContact(ci);
			// FOR DEBUG PhoneBookObj.arr_contacts[ci].showContact();
			ci++;
		}
		else if (!(uinput.compare("SEARCH")))
		{
			PhoneBookObj.searchContacts();
		}
		else if (!(uinput.compare("EXIT")))
		{
			std::cout << "Got EXIT" << "\n";
			return(0);
		}
		else
			std::system("clear");
		
	}
		
	return 0;
}