/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:51:26 by yhruda            #+#    #+#             */
/*   Updated: 2026/05/20 14:20:58 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main() {

  std::cout << "=== AForm class test ===" << std::endl;

  PresidentialPardonForm fa("Alice");
  Bureaucrat b("Bob", 2);
  Bureaucrat c("Charlie", 150);
  std::cout << fa << std::endl;

  std::cout << "=== Signing and executing form ===" << std::endl;

  // will be ok, Bob has grade 2, which is higher than the required grade to
  // sign (25) and execute (5) the form.
  b.signForm(fa);
  b.executeForm(fa);

  // will throw an exception, Charlie has grade 150, which is lower than the
  // required grade to sign (25) and execute (5) the form.
  c.signForm(fa);
  c.executeForm(fa);

  // FOR TEST - shouldn't work. uncomment below
  // AForm ftest;

  ShrubberyCreationForm fsc("Garden");
  b.signForm(fsc);
  b.executeForm(fsc);
  

  return 0;
}
