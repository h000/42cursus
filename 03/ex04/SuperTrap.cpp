/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:17:05 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 14:33:52 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(): FragTrap(), NinjaTrap()
{
	std::cout << "SUPER-TP <" << this->name << "> is created" << std::endl;
	this->HP = 100;
	this->maxHP = 100;
	this->EP = 120;
	this->maxEP = 120;
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
}

SuperTrap::SuperTrap(std::string const &name): ClapTrap(name), FragTrap(), NinjaTrap()
{
	std::cout << "SUPER-TP <" << this->name << "> is created" << std::endl;
	this->HP = 100;
	this->maxHP = 100;
	this->EP = 120;
	this->maxEP = 120;
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
}

SuperTrap::SuperTrap(SuperTrap const &other): FragTrap(), NinjaTrap()
{
	std::cout << "SUPER-TP <" << this->name << "> is copied" << std::endl;
	*this = other;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SUPER-TP <" << this->name << "> is deleted" << std::endl;
}

SuperTrap	&SuperTrap::operator=(const SuperTrap &other)
{
	this->HP = other.HP;
	this->maxHP = other.maxHP;
	this->EP = other.EP;
	this->maxEP =other.maxEP;
	this->lv = other.lv;
	this->meleeAttackDamage = other.meleeAttackDamage;
	this->rangedAttackDamage = other.rangedAttackDamage;
	this->armorDamageReduction = other.armorDamageReduction;
	return (*this);
}

void	SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);
}

void	SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}