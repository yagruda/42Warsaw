/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:47:18 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/04 18:03:55 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Write class names in UpperCamelCase format. Files containing class code will
always be named according to the class name. For instance:
ClassName.hpp/ClassName.h, ClassName.cpp, or ClassName.tpp. Then, if you
have a header file containing the definition of a class "BrickWall" standing for a
brick wall, its name will be BrickWall.hpp

Unless specified otherwise, every output message must end with a newline character
and be displayed to the standard output.

*/

#include "global.hpp"

PhoneBook::PhoneBook()
{
	for (int i = 0; i < 8; i++)
	{
		this->arr_contacts[i].index = i;
	}
}

void PhoneBook::addContact(int i)
{
	int num;
	string temp;

	system("clear");
	std::cout << "Enter Contact's Number" << std::endl;
	std::cin >> num;
	// Validate phone number input
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid phone number. Please enter digits only. Write \"ADD\" to add a contact again" << std::endl;
		return;
	}
	this->arr_contacts[i].phone_number = num; 
	system("clear");
	std::cout << "Enter Contact's First Name" << std::endl;
	std::cin >> temp;
	this->arr_contacts[i].first_name = temp;
	system("clear");
	std::cout << "Enter Contact's Last Name" << std::endl;
	std::cin >> temp;
	this->arr_contacts[i].last_name = temp;
	system("clear");
	std::cout << "Enter Contact's Nick Name" << std::endl;
	std::cin >> temp;
	this->arr_contacts[i].nick_name = temp;
	system("clear");
	std::cout << "Enter Secret" << std::endl;
	std::cin >> temp;
	this->arr_contacts[i].secret = temp;
	this->arr_contacts[i].is_used = 1;
	system("clear");
	std::cout << "Contact Added Sucessfully" << std::endl;
}

void PhoneBook::searchContacts()
{
	std::cout << "Yo";
	int i = 0;
	
	while (this->arr_contacts[i].is_used == 1)
	{
		std::cout << this->arr_contacts[i].index << this->arr_contacts[i].first_name << ' ' << this->arr_contacts[i].last_name << ' ' << this->arr_contacts[i].nick_name << std::endl;
		i++;
	}
}