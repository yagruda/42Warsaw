/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:49:59 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/16 16:30:22 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.hpp"

// TBD: can store maximum 8 contacts. If tries to add 9th - replace the oldest one (the one at the beggining of a stack)
class PhoneBook
{
	public:
		Contact arr_contacts[8]; // Transfer to private at the end
		PhoneBook(); 
		void addContact(int i);
		void searchContacts();
};


//Truncate adn Replace Transfer Here from main
