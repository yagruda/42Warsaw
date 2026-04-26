/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:51:28 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/20 14:27:52 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Please note that exception classes do not have to be designed in
Orthodox Canonical Form.
*/

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	public:
		const std::string _name;
		unsigned int _grade; // 1 is the highest, 150 is the lowest

		Bureaucrat(const std::string name, unsigned int grade);

		// checker
		void GradeTooHighException() const;
		void GradeTooLowException() const;
		
		// getters 
		const std::string getName() const;
		unsigned int getGrade() const;
		
		// modifiers 
		void incrementGrade();
		void decrementGrade();
};

#endif