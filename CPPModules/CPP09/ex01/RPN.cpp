#include "RPN.hpp"
#include <sstream>

RPN::RPN() {
	// Constructor noimplementation
}

RPN::~RPN() {
	// Destructor noimplementation
}

RPN::RPN(const RPN& other) {
	if (this != &other) 
		*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		_operands = other._operands;
	return *this;
}

void RPN::evaluate(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;

	while (std::getline(iss, token, ' '))
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			int a = _operands.top();
			_operands.pop();
			int b = _operands.top();
			_operands.pop();

			if (token == "+")
				_operands.push(a+b);
			else if (token == "-")
				_operands.push(b-a);
			else if(token == "*")
				_operands.push(a*b);
			else if (token == "/")
				_operands.push(b/a);
		}
		else if ((isdigit(token[0])) && (token.length() == 1))
		{
			_operands.push(std::stoi(token));
		}
		else 
		{
			std::cerr << "Error" << std::endl;
			break;
		}
	}
	
	while (!_operands.empty())
	{
		std::cout << _operands.top() << std::endl;
		_operands.pop();
	}

}