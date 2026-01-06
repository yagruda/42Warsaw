/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:47:09 by yhruda            #+#    #+#             */
/*   Updated: 2025/12/29 13:59:48 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain; // Reference. Must be initialized when created. Cannot be NULL. Once initialized, cannot be changed to reference another variable.
	
	std::cout << "Address of brain: " << &brain << std::endl;
	std::cout << "Address held by stringPTR: " << &stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "value of string: " << brain << std::endl;
	std::cout << "value of stringPTR: " << stringPTR << std::endl;
	std::cout << "value of stringREF: " << stringREF << std::endl;

	
	return 0;
}