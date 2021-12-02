/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:17:31 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:17:32 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "SC4V-TP <" << this->name << "> is created" << std::endl;
	this->EP = 50;
	this->maxEP = 50;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
}

ScavTrap::ScavTrap(std::string const &name): ClapTrap(name)
{
	std::cout << "SC4V-TP <" << this->name << "> is created" << std::endl;
	this->EP = 50;
	this->maxEP = 50;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
}

ScavTrap::ScavTrap(ScavTrap const &other): ClapTrap(other)
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