#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() { std::cout << "Intern Default constructor called." << std::endl; }
Intern::Intern(const Intern &other) { (void)other; std::cout << "Intern Copy constructor called." << std::endl;}
Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern Copy assignment called." << std::endl;
	if (this == &other)
		return *this;
	return *this;
}
Intern::~Intern() { std::cout << "Intern Destructor called." << std::endl; }

AForm* createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* createPresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string formName, const std::string target)
{
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	AForm* (*formCreators[])(const std::string) = {&createShrubbery, &createRobotomy, &createPresidential};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return formCreators[i](target);
		}
	}
	std::cout << "Intern couldn't find the form: " << formName << std::endl;
	return NULL;
}