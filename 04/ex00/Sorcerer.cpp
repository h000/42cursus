/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:45:03 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:45:11 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title)
{
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &other)
{
	*this = other;
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title
	<< ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer	&Sorcerer::operator=(const Sorcerer &other)
{
	this->name = other.name;
	this->title = other.title;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Sorcerer& sc)
{
	os << "I am " << sc.getName() << ", "
	<< sc.getTitle() << ", and I like ponies!\n";
	return (os);
}

std::string		Sorcerer::getName() const
{
	return (this->name);
}

std::string		Sorcerer::getTitle() const
{
	return (this->title);
}



void			Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}