#include "Array.hpp"
#include <iostream>
#include <string>
#include <exception>


template <typename T>
void printArray(Array<T> &a) {
	for (unsigned int i = 0; i < a.size(); i++) {
		std::cout << a[i] << std::endl;
	}
	std::cout << "end of the a list" << std::endl;
}

int main() {

  	Array<int> a(4);
	Array<int> b(3);
	Array<int> c;
	Array<int> *test = new Array<int>(5);
	printArray(a);
	b[2] = 3;
	printArray(b);
	try{
		b[7] = 3;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	printArray(b);
	a[1] = 6;
	printArray(a);
	a = b;
	printArray(a);
	a[2] = 4;
	printArray(b);
	printArray(a);
	printArray(c);

	printArray(*test);
	(*test)[2] = 20;
	printArray(*test);


    delete test;
    return 0;
}
