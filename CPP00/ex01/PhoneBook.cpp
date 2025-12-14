/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:47:18 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/14 14:12:55 by yhruda           ###   ########.fr       */
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

static std::string formatColumn(const std::string &value)
{
	if (value.length() > MaxLen)
		return value.substr(0, MaxLen - 1) + ".";
	return value;
}

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

	std::system("clear");
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
	std::system("clear");
	std::cout << "Enter Contact's First Name" << std::endl;
	std::cin >> temp;
	this->arr_contacts[i].first_name = temp;
	std::system("clear");
	std::cout << "Enter Contact's Last Name" << std::endl;
	std::cin >> temp;
	this->arr_contacts[i].last_name = temp;
	std::system("clear");
	std::cout << "Enter Contact's Nick Name" << std::endl;
	std::cin >> temp;
	this->arr_contacts[i].nick_name = temp;
	std::system("clear");
	std::cout << "Enter Secret" << std::endl;
	std::cin >> temp;
	this->arr_contacts[i].secret = temp;
	this->arr_contacts[i].is_used = 1;
	std::system("clear");
	std::cout << "Contact Added Sucessfully" << std::endl;
}

void PhoneBook::searchContacts()
{
	int i = 0;

	// no contacts
	if (this->arr_contacts[0].is_used == 0)
	{
		std::cout << "Empty contacts list" << std::endl;
		return;
	}
	
	std::cout << std::setw(MaxLen) << "Index" << '|' \
		<< std::setw(MaxLen) << "First Name" << '|' \
		<< std::setw(MaxLen) << "Last Name" << '|' \
		<< std::setw(MaxLen) << "Nickname" << std::endl;

	while (this->arr_contacts[i].is_used == 1)
	{
		std::cout << std::setw(MaxLen) << this->arr_contacts[i].index << '|' \
			<< std::setw(MaxLen) << formatColumn(this->arr_contacts[i].first_name) << '|' \
			<< std::setw(MaxLen) << formatColumn(this->arr_contacts[i].last_name) << '|' \
			<< std::setw(MaxLen) << formatColumn(this->arr_contacts[i].nick_name) << std::endl;
		i++;
	}

	std::cout << "Enter index to see full contact's information" << std::endl;
	std::cin >> i;
	if (std::cin.fail() || i > 7 || i < 0)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index input. Please enter digits only. Write \"SEARCH\" to search again" << std::endl;
		return;
	}
	
	if (this->arr_contacts[i].is_used == 1)
	{
		this->arr_contacts[i].showContact();
	}
	else
	{
		std::cout << "Contact at this index does not exist. Write \"SEARCH\" to search again" << std::endl;
		return;
	}


}
