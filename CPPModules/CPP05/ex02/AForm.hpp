/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:48:47 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/30 15:09:50 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _is_signed;
  const unsigned int _grade_sign_required;
  const unsigned int _grade_execute_required;

public:
  AForm();
  AForm(const std::string name, unsigned int grade_sign,
        unsigned int grade_execute);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm() = 0;

  // ex02 update
  /*
  Any developer (e.g junior dev) who creates a new form MUST provide an execute
  method, or the compiler will completely reject the code
  */
  virtual void execute(Bureaucrat const &executor) const = 0;

  const std::string getName() const;
  bool getSignStatus() const;
  unsigned int getSignGrade() const;
  unsigned int getExecGrade() const;

  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };
  class FormNotSignedException : public std::exception {
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif
