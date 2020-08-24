/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:17:03 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 13:16:01 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

int main(void)
{
	std::cout << "=============Create ClapTraps============" << std::endl;
	SuperTrap	*super = new SuperTrap("SUPER");
	FragTrap	*frag = new FragTrap("FR4G");
	ScavTrap	*scav = new ScavTrap("SC4V");
	NinjaTrap	*ninja = new NinjaTrap("NINJA");
	std::cout << "\n=======Take damage and Be repaired=======" << std::endl;
	super->takeDamage(24);
	super->beRepaired(50);
	super->takeDamage(42);
	super->takeDamage(100);
	super->beRepaired(125);
	std::cout << "\n=============Melee Attack================" << std::endl;
	super->meleeAttack("CL4P-TP");
	std::cout << "\n=============Ranged Attack===============" << std::endl;
	super->rangedAttack("CL4P-TP");
	std::cout << "\n=====Vaulthunter.exe (random attack)=====" << std::endl;
	super->vaulthunter_dot_exe("CL4P-TP");
	super->vaulthunter_dot_exe("CL4P-TP");
	super->vaulthunter_dot_exe("CL4P-TP");
	super->vaulthunter_dot_exe("CL4P-TP");
	super->vaulthunter_dot_exe("CL4P-TP");
	std::cout << "\n=============NinjaShoebox================" << std::endl;
	super->ninjaShoebox(*frag);
	super->ninjaShoebox(*scav);
	super->ninjaShoebox(*ninja);
	std::cout << "\n=============Delete ClapTraps============" << std::endl;
	delete frag;
	delete scav;
	delete ninja;
	delete super;
	return (0);
}