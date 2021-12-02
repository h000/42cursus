/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:50:40 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:51:39 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){}

Cure::Cure(Cure const &other) : AMateria("cure")
{
	*this = other;
}

Cure::~Cure(){}

Cure	&Cure::operator=(Cure const &other)
{
	this->_type = other._type;
	this->_xp = other._xp;
	return (*this);
}

Cure* Cure::clone() const
{
	Cure *copy = new Cure(*this);
	return (copy);
}

void Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals NAME’s wounds *" << std::endl;
}