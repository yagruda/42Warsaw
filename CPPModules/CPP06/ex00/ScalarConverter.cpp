#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

// assign
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

// copy
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	if (this != &other) {}

	*this = other;
}

void ScalarConverter::convertFromChar(const std::string& literal)
{
	std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(literal[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;

}

void ScalarConverter::convertFromNumber(const std::string& literal)
{
	double number = std::atof(literal.c_str());

	if (number < 0 || number > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(number)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;

	if (number < static_cast<double>(std::numeric_limits<int>::min()) || number > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(number) << std::endl;

	std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl;
	std::cout << "double: " << number << ".0" << std::endl;
}

void ScalarConverter::convertFromFinite(const std::string& literal)
 {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;

  if (literal.find("nan") != std::string::npos) {
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  } else {
    std::cout << "float: " << literal[0] << "inff" << std::endl;
    std::cout << "double: " << literal[0] << "inf" << std::endl;
  }
}



void ScalarConverter::convert(const std::string& literal)
{
	// detect what is the type of literal and convert it to correspond type
	// after that convert it to other types and print the result
	if (literal.empty())
	   	std::cout << "Empty" << std::endl;
	else if (isChar(literal))
	{	
		std::cout << "Literal is a char." << std::endl;
		convertFromChar(literal);
	}
	else if (isInt(literal))
	{
		std::cout << "Literal is an int." << std::endl;
		convertFromNumber(literal);
	}
	else if (isFloat(literal))
	{
		std::cout << "Literal is a float." << std::endl;
		convertFromNumber(literal);
	}
	else if (isDouble(literal))
	{
		std::cout << "Literal is a double." << std::endl;
		convertFromNumber(literal);
	}
	else if (isFinite(literal) || isFiniteFloat(literal))
	{
		std::cout << "Literal is a finite value." << std::endl;
		convertFromFinite(literal);
	}
	else
		std::cerr << "Bro stop, you need to provide a valid literal." << std::endl;
	

}
