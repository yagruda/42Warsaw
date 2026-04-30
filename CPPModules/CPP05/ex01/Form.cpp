/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:48:49 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/26 17:31:00 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
following exceptions will be thrown if a form’s grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.

*/

const std::string Form::getName() const
{
	return _name;
}

unsigned int Form::getExecGrade() const
{
	return _grade_execute;
}

unsigned int Form::getSignGrade() const
{
	return _grade_sign;
}

bool Form::getSignStatus() const
{
	return _is_signed;
}

std::ostream& operator<<(std::ostream &os, const Form &obj)
{
	os << "Form:" << obj.getName() << ", and it's " << (obj.getSignStatus() ? "signed" : "not signed") << "required grade to sign is " << obj.getSignGrade() << "and to execute is" << obj.getExecGrade();
	
	return os;
}
