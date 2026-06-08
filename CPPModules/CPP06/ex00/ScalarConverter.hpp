#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter
{
	private:

	ScalarConverter();
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);
	ScalarConverter(const ScalarConverter& other);

	// member functions are static because we don't create instance of this class
	// and we still will be able to call them

	static bool isChar(const std::string& literal);
	static bool isInt(const std::string& literal);
	static bool isFloat(const std::string& literal);
	static bool isDouble(const std::string& literal);
	static bool isFinite(const std::string& literal);
	static bool isFiniteFloat(const std::string& literal);
	
	static void convertFromChar(const std::string& literal);
	static void convertFromNumber(const std::string& literal);
	static void convertFromFinite(const std::string& literal);

	public:
	static void convert(const std::string& literal);

};

#endif