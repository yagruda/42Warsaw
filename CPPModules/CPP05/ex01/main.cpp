/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:51:26 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/30 15:22:25 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
  // try
  // {
  // 	Bureaucrat a("Pan", 1);
  // 	a.incrementGrade();

  // }
  // catch(const std::exception& e)
  // {
  // 	std::cout << e.what() << std::endl;
  // }

  // try
  // {
  // 	Bureaucrat a("Dmitri", 151);
  // 	std::cout << a << std::endl; // if constructor throws an exception, this
  // line will not be executed
  // }
  // catch(std::exception &e) // catch is looking for exception class or any
  // class that inherits from it (our case)
  // {
  // 	std::cout << e.what() << std::endl;
  // }

  // try
  // {
  // 	Bureaucrat a("Mowi", 0);
  // 	std::cout << a << std::endl;
  // }
  // catch(std::exception &e)
  // {
  // 	std::cout << e.what() << std::endl;
  // }

  // try
  // {
  // 	Bureaucrat a("Niemaproblem", 15);
  // 	std::cout<< a.getGrade() << std::endl;
  // 	a.decrementGrade();
  // 	std::cout<< a.getGrade() << std::endl;
  // 	a.incrementGrade();
  // 	std::cout<< a.getGrade() << std::endl;
  // }
  // catch(std::exception &e)
  // {
  // 	std::cout << e.what() << std::endl;
  // }
  // catch(int)
  // {
  // 	std::cout << "I will never run" << std::endl;
  // }

  try {
    Form c("Form1", 1111, 1111);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  Form a("Form2", 50, 50);
  Form b;
  Form c(a);
  b = a;
  std::cout << b << std::endl;
  std::cout << c << std::endl;

  std::cout << "-----------------" << std::endl;

  try {
    a.beSigned(Bureaucrat("Dmitri", 49));
    std::cout << a << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  try {
    a.beSigned(Bureaucrat("Yokla", 3000));
    std::cout << a << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}
