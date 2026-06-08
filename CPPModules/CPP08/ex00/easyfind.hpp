#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

class ValueNotFound: public std::exception
{
	public:
	virtual const char* what() const throw();
};

// maybe we can take & as the input to avoid copying the container, but it is not specified in the subject
template <typename T> void easyfind(T container, int findValue);

#include "easyfind.tpp"



#endif
