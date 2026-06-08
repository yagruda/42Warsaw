/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:48:49 by yhruda            #+#    #+#             */
/*   Updated: 2026/05/01 10:32:40 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
following exceptions will be thrown if a form’s grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.

*/

Form::Form() : _name("Noname Form"), _is_signed(false), _grade_sign_required(140), _grade_execute_required(140) {
	std::cout << "Form Default constructor called." << std::endl;
}

Form::Form(const std::string name, unsigned int grade_sign, unsigned int grade_execute) : _name(name), _is_signed(false), _grade_sign_required(grade_sign), _grade_execute_required(grade_execute)
{
	if (grade_sign < 1 || grade_execute < 1) throw GradeTooHighException();
	else if (grade_sign > 150 || grade_execute > 150) throw GradeTooLowException();
	std::cout << "Form constructor called." << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor called." << std::endl;
}


Form::Form(const Form &other): _name(other._name), _is_signed(other._is_signed), _grade_sign_required(other._grade_sign_required), _grade_execute_required(other._grade_execute_required)
{
	std::cout << "Form Copy constructor called." << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form Copy assignment called." << std::endl;
	if (this == &other)
		return *this;
	this->_is_signed = other._is_signed;
	
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Form &obj)
{
	os << "Form: " << obj.getName() << ", and it's " << (obj.getSignStatus() ? "signed " : "not signed ") << "required grade to sign is " << obj.getSignGrade() << " and to execute is " << obj.getExecGrade();
	
	return os;
}

const std::string Form::getName() const
{
	return _name;
}

unsigned int Form::getExecGrade() const
{
	return _grade_execute_required;
}

unsigned int Form::getSignGrade() const
{
	return _grade_sign_required;
}

bool Form::getSignStatus() const
{
	return _is_signed;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_sign_required)
	{
		throw GradeTooLowException();
	}
	else
	{
		this->_is_signed = true;
	}
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("Grade is too High!");
}
const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade is too Low!");
}

