/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:49:55 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/04 17:58:19 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The contact fields are: first name, last name, nickname, phone number, and
darkest secret. A saved contact can’t have empty fields.
*/

#include "global.hpp"

class Contact
{
	public:
		int index;
		long long phone_number;
		string first_name;
		string last_name;
		string nick_name;
		string secret;
		int is_used;
		Contact();
		~Contact();
		void showContact();
};

