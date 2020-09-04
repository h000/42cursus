/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:54:34 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:54:56 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
Form("shrubbery", 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) :
Form("shrubbery", 145, 137), target(other.target)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	Form::operator=(other);
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string	filename;
	std::ofstream	ofs;

	Form::execute(executor);
	filename = this->target + "_shruberry";
	ofs.open(filename, std::fstream::out | std::fstream::app);
	if (ofs.is_open())
	{
		ofs << "   {{{{}}}}}}}}}}" << std::endl;
		ofs << "  }}}}}}}}}{{(`){{" << std::endl;
		ofs << " {}}}}}{{{{(`)}}{{{}" << std::endl;
		ofs << " {{{(`)}}}}}}}{}}}}}" << std::endl;
		ofs << "{{{{{{{{(`)}}}}}}}}}}" << std::endl;
		ofs << "{{{{{{{}{{{{(`)}}}}}}" << std::endl;
		ofs << " {{{{{(`)   {{{{(`)}'" << std::endl;
		ofs << "  `\"\"'\" |   | \"" << std::endl;
		ofs.close();
	}
}