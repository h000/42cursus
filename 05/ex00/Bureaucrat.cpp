#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) :
name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) :
name(name), grade(grade)
{
	*this = other;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	this->grade = other.grade;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "BureaucratException: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "BureaucratException: Grade is too low";
}

std::string const	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	 Bureaucrat::incrementGrade()
{
	--this->grade;
	if (this->grade < 1)
		throw GradeTooHighException();
}

void	 Bureaucrat::decrementGrade()
{
	++this->grade;
	if (this->grade > 150)
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}