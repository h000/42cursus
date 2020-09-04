/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:52:36 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:53:11 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
#include <exception>

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
		int			getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b);

#endif