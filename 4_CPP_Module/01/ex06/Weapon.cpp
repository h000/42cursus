/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:19:00 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:19:00 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}
Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(){}

void				Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string	&Weapon::getType()
{
	return (this->type);
}