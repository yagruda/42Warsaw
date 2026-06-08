/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:51:26 by yhruda            #+#    #+#             */
/*   Updated: 2026/05/21 09:03:49 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void intern_test(void)
{
  std::cout << "\n=== Intern test ===" << std::endl;
  Intern someRandomIntern;
  AForm* rrf;
  rrf = someRandomIntern.makeForm("shrubbery creation","Bender");
  if (rrf)
  {
    Bureaucrat b("Bob", 1);
    b.signForm(*rrf);
    b.executeForm(*rrf);
    delete rrf;
  }
  else
    std::cout << "Intern couldn't create the form." << std::endl;
}

int main() {

  
  intern_test();

  return 0;
}
