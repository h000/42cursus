/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:53:58 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:54:42 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		virtual ~Form();
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
		class	UnsignedFormException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		std::string		getName() const;
		int				getGradeToSign() const;
		int				getGradeToExec() const;
		bool			isSigned() const;
		void			beSigned(Bureaucrat b);
		virtual	void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &os, Form const &f);

#endif