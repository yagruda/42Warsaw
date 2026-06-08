/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:21:30 by yhruda            #+#    #+#             */
/*   Updated: 2026/05/20 14:21:21 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
class AForm;

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  /*
  In C++, virtual propagates down automatically. Once you declare something
  virtual in the base class, all overrides in derived classes are automatically
  virtual — whether you write the keyword or not. But it's a good practice to
  write it as virtual in derived classes too to make it clear for the reader of
  the code, not for the compiler.
  */
  virtual ~ShrubberyCreationForm();
  virtual void execute(Bureaucrat const &executor) const;
};

#endif
