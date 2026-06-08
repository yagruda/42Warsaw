#include "easyfind.hpp"

// iterator type depends on the containter type, so we need to use typename to specify it
// iterator is a pointer to the element in the container, so we can use it to access the value and the position of the element
// it goes from the beginning of the container to the end of the container, and it is incremented by 1 in each iteration
// std::find is a function that takes a range of elements and a value to find, and returns an iterator to the first element that is equal to the value, or the end of the range if the value is not found
// std::distance is a function that takes two iterators and returns the distance between them, which is the number of elements between them
	
const char* ValueNotFound::what() const throw()
{
	return "Value not found in the container.";
}

template <typename T> void easyfind(T container, int findValue)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), findValue);
	if (it == container.end())
		throw ValueNotFound();
	else
		std::cout << "Value " << findValue << " found in the container in position " << std::distance(container.begin(), it) << std::endl;
}

