/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:51:30 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/30 13:45:42 by yhruda           ###   ########.fr       */
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

Bureaucrat::Bureaucrat() : _name("Unamed Bureac"), _grade(150) {
  std::cout << "Bureaucrat Default constructor called." << std::endl;
}


Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): _name(name)
{
	if (grade < 1) throw GradeTooHighException();
	else if (grade > 150) throw GradeTooLowException();

	_grade = grade;
	
	std::cout << "Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
  std::cout << "Bureaucrat Copy constructor called." << std::endl;
} 

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "Bureaucrat Copy assignment called." << std::endl;
  if (this == &other)
    return *this;
  this->_grade = other._grade;
  return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1) throw GradeTooHighException();
	else _grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150) throw GradeTooLowException();
	else _grade++;
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

unsigned int Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too High!");
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too Low!");
}

