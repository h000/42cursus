/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:16:42 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 13:31:37 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	name("default")
{
	std::cout << "Claptrap <" << this->name << "> is created" << std::endl;
	this->HP = 100;
	this->maxHP = 100;
	this->EP = 100;
	this->maxEP = 100;
	this->lv = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;

}

ClapTrap::ClapTrap(std::string const &name):
	name(name)
{
	std::cout << "Claptrap <" << this->name << "> is created" << std::endl;
	this->HP = 100;
	this->maxHP = 100;
	this->EP = 100;
	this->maxEP = 100;
	this->lv = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
}

ClapTrap::ClapTrap(ClapTrap const &other):
	name(other.name)
{
	std::cout << "Claptrap <" << this->name << "> is copied" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap <" << this->name << "> is deleted" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
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

void	ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << "Claptrap <" << this->name << "> attacks <" << target
	<< "> at range, causing " << this->rangedAttackDamage
	<< " points of damage!" << std::endl;
}

void	ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "Claptrap <" << this->name << "> attacks <" << target
	<< "> at melee, causing " << this->meleeAttackDamage
	<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	damage;

	damage = amount - this->armorDamageReduction;
	if (this->HP < damage)
		damage = this->HP;
	this->HP -= damage;
	std::cout << "Claptrap <" << this->name << "> takes " \
	<< damage << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	hitPoints;

	hitPoints = this->HP + amount;
	if (hitPoints > this->maxHP)
		hitPoints = this->maxHP;
	this->HP = hitPoints;
	std::cout << "Claptrap <" << this->name << "> is repaired, Hit Points : " \
	<< this->HP << " !" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}