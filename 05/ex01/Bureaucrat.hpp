#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
#include <exception>

class	Form;

class	Bureaucrat
{
	private:
		Bureaucrat();
		std::string	const	name;
		int					grade;
	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat();
		Bureaucrat	&operator=(Bureaucrat const &other);
		class	GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const noexcept;
		};
		std::string const	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &f);
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b);

#endif