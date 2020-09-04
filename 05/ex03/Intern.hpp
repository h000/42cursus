/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:55:49 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:56:25 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		~Intern();
		Intern	&operator=(Intern const &other);
		Form	*makeForm(std::string name, std::string target);
		Form	*createPresidentialPardon(std::string target);
		Form	*createRobotomyRequest(std::string target);
		Form	*createShrubberyCreation(std::string target);
};

#endif