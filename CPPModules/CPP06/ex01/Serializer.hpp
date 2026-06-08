#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

#include <stdint.h>
#include <iostream>

class Serializer
{
	private:
	Serializer();
	~Serializer();
	Serializer& operator=(const Serializer& other);
	Serializer(const Serializer& other);

	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif