/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:50:23 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:52:04 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type), _xp(0){}

AMateria::AMateria(AMateria const &other)
{
	*this = other;
}

AMateria::~AMateria(){}

AMateria	&AMateria::operator=(AMateria const &other)
{
	this->_type = other._type;
	this->_xp = other._xp;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

unsigned int AMateria::getXP() const
{
	return (this->_xp);
}

void AMateria::use(ICharacter& target)
{
	this->_xp += 10;
	(void)target;
}