/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:17:05 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:56:16 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(): ClapTrap()
{
	std::cout << "NINJA-TP <" << this->name << "> is created" << std::endl;
	this->HP = 60;
	this->maxHP = 60;
	this->EP = 120;
	this->maxEP = 120;
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 5;
	this->armorDamageReduction = 0;
}

NinjaTrap::NinjaTrap(std::string const &name): ClapTrap(name)
{
	std::cout << "NINJA-TP <" << this->name << "> is created" << std::endl;
	this->HP = 60;
	this->maxHP = 60;
	this->EP = 120;
	this->maxEP = 120;
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 5;
	this->armorDamageReduction = 0;
}

NinjaTrap::NinjaTrap(NinjaTrap const &other): ClapTrap(other)
{
	std::cout << "NINJA-TP <" << this->name << "> is copied" << std::endl;
	*this = other;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NINJA-TP <" << this->name << "> is deleted" << std::endl;
}

NinjaTrap	&NinjaTrap::operator=(const NinjaTrap &other)
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

void	NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	std::cout << target.getName() << " is using ninja-trap skill" << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap &target)
{
	std::cout << target.getName() << " is using frag-trap skill" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	std::cout << target.getName() << " is using scav-trap skill" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap &target)
{
	std::cout << target.getName() << " is using scav-trap skill" << std::endl;
}