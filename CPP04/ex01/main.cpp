/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:42:41 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/19 15:17:58 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// check for malloc (leaks on mac os)


int main()
{
  const Animal *Animal1 = new Animal();
  const Animal *Animal2 = Animal1;
  const Animal *Dog1 = new Dog();
  const Animal *i = new Cat();
  std::cout << Dog1->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // Outputs the cat sound!
  Dog1->makeSound();
  Animal1->makeSound();
  Animal2->makeSound();

  delete Animal1;
  delete Dog1;
  delete i;

  std::cout << "==== Wrong classes tests ====\n";

  // Additional tests with WrongCat
  const WrongAnimal *metaa = new WrongAnimal();
  const WrongAnimal *jj = new WrongCat();
  const WrongAnimal *ii = new WrongCat();
  std::cout << jj->getType() << " " << std::endl;
  std::cout << ii->getType() << " " << std::endl;
  ii->makeSound(); // will output the cat sound!
  jj->makeSound();
  metaa->makeSound();

  delete metaa;
  delete jj;
  delete ii;

  std::cout << "==== Aniaml Brain's tests ====\n";

  Animal* Animals[50];
  for (int i = 0; i < 25; i++)
    Animals[i] = new Cat();
  for (int i = 25; i < 50; i++)
    Animals[i] = new Dog();
  for (int i = 0; i < 50; i++)
    delete Animals[i];

  return 0;
}
