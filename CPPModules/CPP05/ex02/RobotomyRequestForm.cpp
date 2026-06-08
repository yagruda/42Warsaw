/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:21:26 by yhruda            #+#    #+#             */
/*   Updated: 2026/05/20 14:16:06 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request AForm", 72, 45), _target("Default Target")
{
	std::cout << "RobotomyRequestForm Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("Robotomy Request AForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm Copy constructor called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm Copy assignment called" << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "Making some drilling noises..." << std::endl;
	rand() % 2 == 0 ? std::cout << this->_target << " has been robotomized successfully." << std::endl
					 : std::cout << "Failed to robotomize " << this->_target << "." << std::endl;
}
