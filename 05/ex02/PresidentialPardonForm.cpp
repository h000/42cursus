#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
Form("presidential", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) :
Form("presidential", 25, 5), target(other.target)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	Form::operator=(other);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}