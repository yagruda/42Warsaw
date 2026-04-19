/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:42:41 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/19 16:31:50 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
  const Animal *x = new Dog();
  const Animal *y = new Cat();
  std::cout << x->getType() << " " << std::endl;
  std::cout << y->getType() << " " << std::endl;
  y->makeSound(); 
  x->makeSound();
  
  const WrongAnimal *wrongCat = new WrongCat();
  wrongCat->makeSound();

  delete x;
  delete y;
  delete wrongCat;

  const Animal *testA = new Dog();
  const Animal *testB = new Cat();
  testA->makeSound();
  testB->makeSound();
  std::cout << testA->getType() << " " << std::endl;
  delete testA; 
  delete testB;


  return 0;
}
