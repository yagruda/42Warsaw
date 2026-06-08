/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:26:45 by yhruda            #+#    #+#             */
/*   Updated: 2026/05/21 12:17:37 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cout << "------TESTS-----" << std::endl;
		ScalarConverter::convert(""); 
		ScalarConverter::convert("a");
		ScalarConverter::convert("nan");
		ScalarConverter::convert("+inf");
		ScalarConverter::convert("-inf");
		ScalarConverter::convert("nanf");
		ScalarConverter::convert("+inff");
		ScalarConverter::convert("-inff");
		ScalarConverter::convert("0");
		ScalarConverter::convert("42");
		ScalarConverter::convert("42.0f");
		ScalarConverter::convert("-42.0f");
		ScalarConverter::convert("42.0");
		ScalarConverter::convert("-42.0");
		ScalarConverter::convert("0.0");
		std::cout << "------END OF TESTS-----" << std::endl;
		return 0;
	}
	if (argc != 2)
	{
		std::cerr << "Bro stop, you need to provide exactly one argument." << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
	
	return 0;
}