/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:17:35 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:17:35 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
std::cout << "=============Create FragTrap=============" << std::endl;
	FragTrap	*frag = new FragTrap("FR4G");
	std::cout << "\n=======Take damage and Be repaired=======" << std::endl;
	frag->takeDamage(24);
	frag->beRepaired(50);
	frag->takeDamage(42);
	frag->takeDamage(100);
	frag->beRepaired(125);
	std::cout << "\n=============Melee Attack================" << std::endl;
	frag->meleeAttack("CL4P-TP");
	std::cout << "\n=============Ranged Attack===============" << std::endl;
	frag->rangedAttack("CL4P-TP");
	std::cout << "\n=====Vaulthunter.exe (random attack)=====" << std::endl;
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->vaulthunter_dot_exe("CL4P-TP");
	frag->vaulthunter_dot_exe("CL4P-TP");
	std::cout << "\n=============Delete FragTrap=============" << std::endl;
	delete frag;
	std::cout << "\n=============Create ScavTrap=============" << std::endl;
	ScavTrap	*scav = new ScavTrap("SC4V");
	std::cout << "\n=======Take damage and Be repaired=======" << std::endl;
	scav->takeDamage(24);
	scav->beRepaired(50);
	scav->takeDamage(42);
	scav->takeDamage(100);
	scav->beRepaired(125);
	std::cout << "\n=============Melee Attack================" << std::endl;
	scav->meleeAttack("CL4P-TP");
	std::cout << "\n=============Ranged Attack===============" << std::endl;
	scav->rangedAttack("CL4P-TP");
	std::cout << "\n=======Challenge Newcomer (random)=======" << std::endl;
	scav->challengeNewcomer();
	std::cout << "\n=============Delete ScavTrap=============" << std::endl;
	delete scav;
	return (0);
}