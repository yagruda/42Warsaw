/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:49:57 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/14 14:14:12 by yhruda           ###   ########.fr       */
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
	std::cout << this->index << '\n' << this->first_name << '\n' << this->last_name << '\n' << this->nick_name <<std::endl;
}