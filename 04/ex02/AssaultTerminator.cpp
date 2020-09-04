/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:48:35 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:49:42 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}
AssaultTerminator::AssaultTerminator(const AssaultTerminator &other)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	*this = other;
}
AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back..." << std::endl;
}
AssaultTerminator	&AssaultTerminator::operator=(const AssaultTerminator &other)
{
	(void)other;
	return (*this);
}

ISpaceMarine* AssaultTerminator::clone() const
{
	AssaultTerminator *copy = new AssaultTerminator(*this);
    return (copy);
}
void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}
void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}
void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}