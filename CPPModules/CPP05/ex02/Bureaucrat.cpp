/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:51:30 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/30 17:23:53 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Unamed Bureac"), _grade(150) {
  std::cout << "Bureaucrat Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
    : _name(name) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();

  _grade = grade;

  std::cout << "Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {
  std::cout << "Bureaucrat Copy constructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "Bureaucrat Copy assignment called." << std::endl;
  if (this == &other)
    return *this;
  this->_grade = other._grade;
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called." << std::endl;
}

void Bureaucrat::incrementGrade() {
  if (_grade - 1 < 1)
    throw GradeTooHighException();
  else
    _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade + 1 > 150)
    throw GradeTooLowException();
  else
    _grade++;
}

const std::string Bureaucrat::getName() const { return _name; }

unsigned int Bureaucrat::getGrade() const { return _grade; }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
  return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too High!");
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too Low!");
}

// ex01

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->getName() << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

// ex02

void Bureaucrat::executeForm(AForm const &form) const {
  try {
    form.execute(*this);
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->getName() << " couldn't execute " << form.getName()
              << " because " << e.what() << std::endl;
  }
}
