/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:17:58 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:17:59 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():
	name("default")
{
	std::cout << "SC4V-TP <" << this->name << "> is created" << std::endl;
	this->HP = 100;
	this->maxHP = 100;
	this->EP = 50;
	this->maxEP = 50;
	this->lv = 1;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
}

ScavTrap::ScavTrap(std::string const &name):
	name(name)
{
	std::cout << "SC4V-TP <" << this->name << "> is created" << std::endl;
	this->HP = 100;
	this->maxHP = 100;
	this->EP = 50;
	this->maxEP = 50;
	this->lv = 1;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
}

ScavTrap::ScavTrap(ScavTrap const &other):
	name(other.name)
{
	std::cout << "SC4V-TP <" << this->name << "> is copied" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V-TP <" << this->name << "> is deleted" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
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

void	ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "SC4V-TP <" << this->name << "> attacks <" << target
	<< "> at range, causing " << this->rangedAttackDamage
	<< " points of damage!" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "SC4V-TP <" << this->name << "> attacks <" << target
	<< "> at melee, causing " << this->meleeAttackDamage
	<< " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	unsigned int	damage;

	damage = amount - this->armorDamageReduction;
	if (this->HP < damage)
		damage = this->HP;
	this->HP -= damage;
	std::cout << "SC4V-TP <" << this->name << "> takes " \
	<< damage << " points of damage!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	unsigned int	hitPoints;

	hitPoints = this->HP + amount;
	if (hitPoints > this->maxHP)
		hitPoints = this->maxHP;
	this->HP = hitPoints;
	std::cout << "SC4V-TP <" << this->name << "> is repaired, Hit Points : " \
	<< this->HP << " !" << std::endl;
}

 void	ScavTrap::challengeNewcomer()
{
	std::string challenges[5] = {
		"challenge1", "challenge2", "challenge3", "challenge4", "challenge5"};
	// 시드값을 얻기 위한 random_device 생성.
	std::random_device	rd;
	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());
	// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(0, 4);

	std::cout << "ScavTrap choose " << challenges[dis(gen)] << std::endl;

}