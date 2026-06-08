/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:21:28 by yhruda            #+#    #+#             */
/*   Updated: 2026/05/20 14:17:27 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation AForm", 145, 137), _target("Default Target")
{
	std::cout << "ShrubberyCreationForm Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("Shrubbery Creation AForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm Copy constructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm Copy assignment called" << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	// validate in base class function
	AForm::execute(executor);
	std::ofstream file(this->_target + "_shrubbery");
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file " << this->_target + "_shrubbery" << std::endl;
		return;
	}
	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | |     _-" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
	std::cout << "Shrubbery has been created in file: " << this->_target + "_shrubbery" << std::endl;
}