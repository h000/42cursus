#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
#include <exception>

class	Bureaucrat;

class	Form
{
	private:
		Form();
		std::string	const	name;
		bool	_signed;
		int const	gradeToSign;
		int const	gradeToExec;
	public:
		Form(std::string const &name, int const sign, int const execute);
		Form(Form const &other);
		~Form();
		Form	&operator=(Form const &other);
		class	GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class	AlreadySignedException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		std::string		getName() const;
		int				getGradeToSign() const;
		int				getGradeToExec() const;
		bool			isSigned() const;
		void			beSigned(Bureaucrat b);
};

std::ostream	&operator<<(std::ostream &os, Form const &f);

#endif