/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:56:10 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:56:33 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
Form("robotomy", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) :
Form("robotomy", 72, 45), target(other.target)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	Form::operator=(other);
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
	{
		std::cout << this->target << " has been robotomized successfully 50% of the time." << std::endl;
	}
	else
	{
		std::cout << "It's a failure." << std::endl;
	}
}