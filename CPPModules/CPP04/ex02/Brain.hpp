#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	public:
		Brain();
		Brain(const Brain& ex);
		Brain& operator=(const Brain& ex);
		~Brain();

		std::string ideas[100];


};

#endif