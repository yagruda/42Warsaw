/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:48:49 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/30 18:06:42 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("Noname AForm"), _is_signed(false), _grade_sign_required(140),
      _grade_execute_required(140) {
  std::cout << "AForm Default constructor called." << std::endl;
}

AForm::AForm(const std::string name, unsigned int grade_sign,
             unsigned int grade_execute)
    : _name(name), _is_signed(false), _grade_sign_required(grade_sign),
      _grade_execute_required(grade_execute) {
  if (grade_sign < 1 || grade_execute < 1)
    throw GradeTooHighException();
  else if (grade_sign > 150 || grade_execute > 150)
    throw GradeTooLowException();
  std::cout << "AForm constructor called." << std::endl;
}

AForm::~AForm() { std::cout << "AForm Destructor called." << std::endl; }

AForm::AForm(const AForm &other)
    : _name(other._name), _is_signed(other._is_signed),
      _grade_sign_required(other._grade_sign_required),
      _grade_execute_required(other._grade_execute_required) {
  std::cout << "AForm Copy constructor called." << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
  std::cout << "AForm Copy assignment called." << std::endl;
  if (this == &other)
    return *this;
  this->_is_signed = other._is_signed;

  return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &obj) {
  os << "AForm: " << obj.getName() << ", and it's "
     << (obj.getSignStatus() ? "signed " : "not signed ")
     << "required grade to sign is " << obj.getSignGrade()
     << "and to execute is " << obj.getExecGrade();

  return os;
}

const std::string AForm::getName() const { return _name; }

unsigned int AForm::getExecGrade() const { return _grade_execute_required; }

unsigned int AForm::getSignGrade() const { return _grade_sign_required; }

bool AForm::getSignStatus() const { return _is_signed; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->_grade_sign_required) {
    throw GradeTooLowException();
  } else {
    this->_is_signed = true;
  }
}

const char *AForm::GradeTooHighException::what() const throw() {
  return ("Grade is too High!");
}
const char *AForm::GradeTooLowException::what() const throw() {
  return ("Grade is too Low!");
}

// ex02

const char *AForm::FormNotSignedException::what() const throw() {
  return ("Form is not signed!");
}

void AForm::execute(Bureaucrat const &executor) const {
  if (!this->getSignStatus()) {
    throw FormNotSignedException();
  } else if (executor.getGrade() > this->getExecGrade()) {
    throw GradeTooLowException();
  } else {
    std::cout << "AForm " << this->getName() << " is being executed by "
              << executor.getName() << std::endl;
  }
}