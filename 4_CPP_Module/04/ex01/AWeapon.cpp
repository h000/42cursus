/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:45:48 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:47:41 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage):
name(name), apcost(apcost), damage(damage){}

AWeapon::AWeapon(AWeapon const &other)
{
	*this = other;
}

AWeapon::~AWeapon(){}

AWeapon	&AWeapon::operator=(const AWeapon &other)
{
	this->name = other.name;
	this->apcost = other.apcost;
	this->damage = other.damage;
	return (*this);
}

std::string	AWeapon::getName() const
{
	return (this->name);
}

int	AWeapon::getAPCost() const
{
	return (this->apcost);
}

int	AWeapon::getDamage() const
{
	return (this->damage);
}