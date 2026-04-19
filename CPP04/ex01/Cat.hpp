/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:17:34 by yhruda            #+#    #+#             */
/*   Updated: 2026/04/19 15:08:18 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP	

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(const Cat& ex);
		Cat& operator=(const Cat& ex);
		~Cat();
		
		void makeSound() const;
		void giveIdea(int index);
};


#endif