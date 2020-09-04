/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:54:02 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:54:44 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat a("A", 1);
	std::cout << a << std::endl;

	ShrubberyCreationForm shrub("shrub");
	std::cout << shrub << std::endl;
	a.signForm(shrub);
	shrub.execute(a);
	std::cout << std::endl;
	
	RobotomyRequestForm robo("robo");
	std::cout << robo << std::endl;
	a.signForm(robo);
	robo.execute(a);
	robo.execute(a);
	std::cout << std::endl;

	PresidentialPardonForm pres("pres");
	std::cout << pres << std::endl;
	a.signForm(pres);
	pres.execute(a);
	std::cout << std::endl;

	std::cout << "======B cannot execute======" << std::endl;;
	Bureaucrat b("B", 150);
	std::cout << b << std::endl;
	b.executeForm(shrub);
	b.executeForm(robo);
	b.executeForm(pres);
	a.executeForm(robo);

	return (0);
}