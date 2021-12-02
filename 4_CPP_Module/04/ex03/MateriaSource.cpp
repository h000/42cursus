/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:51:25 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:51:48 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource() : _count(0)
{
	for (int i = 0; i < 4; i++)
	{
		_materia[i] = nullptr;
	}
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	*this = other;
}

MateriaSource::~MateriaSource(){}

MateriaSource	&MateriaSource::operator=(MateriaSource const & other)
{
	for (int i = 0; i < this->_count; i++)
	{
		delete _materia[i]; //delete? 아니면 그냥 0?
		this->_materia[i] = nullptr;
	}
	for (int i = 0; i < other._count; i++)
		this->learnMateria(other._materia[i]);
	return (*this);
}

void			MateriaSource::learnMateria(AMateria*	m)
{	
	if (this->_count > 3 || m == nullptr)
		return ;
	this->_materia[this->_count++] = m->clone();
}

AMateria*		MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_count; i++)
	{
		if (this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (0);
}
