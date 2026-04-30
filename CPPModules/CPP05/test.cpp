#include <iostream>

int test_func(int a, int b)
{
	if (a < 0 || b < 0)
	{
		throw(std::exception());
	}

	return (a+b);
}

int main()
{
	try
	{
		std::cout << "return is " << test_func(-1, 2) << std::endl;
	}
	catch(char const*)
	{
		std::cout << "Catch worked" << std::endl;
	}
	catch(int)
	{
		std::cout << "Int catch worked" << std::endl;
	}
	catch(std::invalid_argument &x)
	{
		std::cout << "here Im " << std::endl;
	}
	catch(std::exception &e)
	{
		e.what();
		std::cout << " exception bitch " << e.what() << std::endl;
	}
	
	return 0;
}