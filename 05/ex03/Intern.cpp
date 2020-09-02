#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern::~Intern(){}

Intern	&Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

Form	*Intern::makeForm(std::string name, std::string target)
{
	std::string	formName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	Form*	(Intern::*function[3])(std::string target) = {
		&Intern::createShrubberyCreation,
		&Intern::createRobotomyRequest,
		&Intern::createPresidentialPardon };

	for (int i = 0; i < 3; i++)
	{
		if (name == formName[i])
		{
			return ((this->*(function[i]))(target));
		}
	}
	std::cout << "Not Valid Formname" << std::endl;
	return (nullptr);
}

Form*	Intern::createPresidentialPardon(std::string target)
{
    return (new PresidentialPardonForm(target));
}

Form*	Intern::createRobotomyRequest(std::string target)
{
    return (new RobotomyRequestForm(target));
}

Form*	Intern::createShrubberyCreation(std::string target)
{
    return (new ShrubberyCreationForm(target));
}