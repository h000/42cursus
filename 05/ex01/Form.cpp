#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(std::string const &name, int const sign, int const execute) :
name(name), _signed(false), gradeToSign(sign), gradeToExec(execute)
{
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &other) :
name(other.name), _signed(other._signed), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
	*this = other;
}

Form::~Form(){}

Form	&Form::operator=(Form const &other)
{
	this->_signed = other._signed;

	return (*this);
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "FormException: Grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "FormException: Grade is too low";
}

const char* Form::AlreadySignedException::what() const noexcept
{
	return "FormException: Form is already signed";
}

std::string	Form::getName() const
{
	return (this->name);
}

int	Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (this->gradeToExec);
}

bool	Form::isSigned() const
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat b)
{
	if (this->isSigned() == true)
		throw Form::AlreadySignedException();
	if (b.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &os, Form const &f)
{
	os << "Form " << f.getName() << std::endl;
	os << (f.isSigned() ? "Signed" : "Unsigned") << std::endl;
	os << "grade required to sign : " << f.getGradeToSign() << std::endl;
	os << "grade required to execute : " << f.getGradeToExec() << std::endl;
	return (os);
}