/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:21:17 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/30 18:01:25 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class AForm;

class PresidentialPardonForm : public AForm {
private:
  std::string _target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  /*
  In C++, virtual propagates down automatically. Once you declare something
  virtual in the base class, all overrides in derived classes are automatically
  virtual — whether you write the keyword or not. But it's a good practice to
  write it as virtual in derived classes too to make it clear for the reader of
  the code, not for the compiler.
  */
  virtual ~PresidentialPardonForm();
  virtual void execute(Bureaucrat const &executor) const;
};

#endif