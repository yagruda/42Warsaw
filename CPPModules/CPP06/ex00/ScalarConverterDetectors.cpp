#include "ScalarConverter.hpp"

// isprint checks if c is a printable character
bool ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]));
}

bool ScalarConverter::isInt(const std::string& literal)
{
	// find returns npos if not found
	const size_t minusDetector = literal.find('-');

	// if we have found minus, but it's not the first digit
	if (minusDetector != 0 && minusDetector != std::string::npos)
		return false;
	// return npos if no unmatched character is found
	// means that all characters are digits or minus
	if (literal.find_first_not_of("0123456789-", 0) == std::string::npos)
		return true;

	// if we have found unmatched character, it's not an int
	return false;
}

bool ScalarConverter::isFloat(const std::string& literal)
{	
	const size_t minusDetector = literal.find('-');

	if (minusDetector != 0 && minusDetector != std::string::npos)
		return false;
	if (literal[literal.length() - 1] != 'f')
		return false;
	
	if (literal.find_first_not_of("0123456789.-f", 0) == std::string::npos)
		return true;
	
	return false;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	const size_t minusDetector = literal.find('-');

	if (minusDetector != 0 && minusDetector != std::string::npos)
	return false;
	
	// means we don't have 'f', have only digits, dot and minus
	if (literal.find_first_not_of("0123456789.-", 0) == std::string::npos)
		return true;
	
	return false;
}

bool ScalarConverter::isFinite(const std::string& literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	return false;
}

bool ScalarConverter::isFiniteFloat(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	return false;
}