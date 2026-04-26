/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:51:30 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/20 14:32:59 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*

1) Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception:
Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException. Remember that math is vice versa

2) If the grade goes out of range, both functions must throw the same exceptions as the
constructor.
// 1 is the highest, 150 is the lowest

3) implement an overload of the insertion << operator to print the Bureaucrat’s name and grade in the following format:
<name>, bureaucrat grade <grade>


*/

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) 
{
	try:
		if (grade <= 1 || grade >= 150)
		{
			throw(grade)
		}

	catch(int checked_grade)
	{
		if (checked_grade <= 1)
	}
	std::cout << "contrusctor called" << std::endl;
}
