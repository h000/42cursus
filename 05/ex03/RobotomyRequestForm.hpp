#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "Form.hpp"

class	RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm();
		std::string	target;
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);
		void	execute(Bureaucrat const &executor) const;
};

#endif