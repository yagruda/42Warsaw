/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:51:28 by yhruda            #+#    #+#             */
/*   Updated: 2026/05/20 14:19:35 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

class AForm;

class Bureaucrat {
private:
  const std::string _name;
  unsigned int _grade; // 1 is the highest, 150 is the lowest

public:
  Bureaucrat();
  Bureaucrat(const std::string name, unsigned int grade);

  Bureaucrat &operator=(const Bureaucrat &other);
  Bureaucrat(const Bureaucrat &other);
  ~Bureaucrat();

  // getters
  const std::string getName() const;
  unsigned int getGrade() const;

  // modifiers. vice-versa
  void incrementGrade(); // --
  void decrementGrade(); // ++

  // by default class inherits from private so we need to specify that we want
  // to inherit from public std::exception! throw means that this function can
  // throw an exception, but it does not specify which one. It is a way to
  // indicate that the function may throw an exception, but it does not provide
  // any information about the type of exception that may be thrown. in C++11
  // and later, the throw() specifier is deprecated and should not be used.
  // Instead, you can use noexcept to indicate that a function does not throw
  // any exceptions.
  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };

  // ex01 update

  void signForm(AForm &form);

  // ex 02 update

  // tbd:
  // it's caller, it will catch exception thrown by AFORM::execute()
  void executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif