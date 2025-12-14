/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:49:57 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/02 22:37:57 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.hpp"

int x = 0;

Contact::Contact()
{
	is_used = 0; 
}

Contact::~Contact()
{
	std::cout << "Contact destructor signal finishing" << '\n';
}

void Contact::showContact()
{
	std::cout << this->index << this->first_name << this->last_name << this->nick_name;
}