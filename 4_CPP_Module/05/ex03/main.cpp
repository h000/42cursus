/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:55:53 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:56:27 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern	intern;

	Form	*shrub;
	Form	*robo;
	Form	*pres;

	shrub = intern.makeForm("shrubbery creation", "intern");
	std::cout << *shrub << std::endl;
	robo = intern.makeForm("robotomy request", "intern");
	std::cout << *robo << std::endl;
	pres = intern.makeForm("presidential pardon", "intern");
	std::cout << *pres << std::endl;

	Form	*err = intern.makeForm("wrong name", "intern");
	std::cout << err << std::endl;

	delete	shrub;
	delete	robo;
	delete	pres;
	return (0);
}