#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "Idea";
	}
}

Brain::Brain(const Brain& ex)
{
	*this = ex;
	std::cout << "Brain copy construct called" << std::endl;
}
Brain& Brain::operator=(const Brain& ex)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &ex)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = ex.ideas[i];
	}
	return(*this);

}
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
