/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:55:28 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:56:48 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) :
name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) :
name(other.name), grade(other.grade)
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

void	Bureaucrat::incrementGrade()
{
	--this->grade;
	if (this->grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	++this->grade;
	if (this->grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(Form	&f)
{
	try
	{
			f.beSigned(*this);
			std::cout << this->name << " signs " << f.getName() << std::endl;
	}
	catch (Form::AlreadySignedException &e)
	{
		std::cout << this->name << " cannot sign " << f.getName() << " because the form is already signed" << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->name << " cannot sign " << f.getName() << " because the grade is not high enough to sign." << std::endl;
	}

}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}