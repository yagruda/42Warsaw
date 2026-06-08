/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:21:23 by yhruda            #+#    #+#             */
/*   Updated: 2026/05/20 11:52:05 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon AForm", 25, 5), _target("Default Target") {
  std::cout << "PresidentialPardonForm Default constructor called."
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("Presidential Pardon AForm", 25, 5), _target(target) {
  std::cout << "PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {
  std::cout << "PresidentialPardonForm Copy constructor called." << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  std::cout << "PresidentialPardonForm Copy assignment called." << std::endl;
  if (this == &other)
    return *this;
  AForm::operator=(other);
  this->_target = other._target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm Destructor called." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  // validate in base class function
  AForm::execute(executor);
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
