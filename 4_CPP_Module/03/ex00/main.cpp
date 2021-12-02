/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:18:10 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:18:11 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	std::cout << "=============Create FragTrap=============" << std::endl;
	FragTrap	frag("FR4G");
	std::cout << "\n=======Take damage and Be repaired=======" << std::endl;
	frag.takeDamage(24);
	frag.beRepaired(50);
	frag.takeDamage(42);
	frag.takeDamage(100);
	frag.beRepaired(125);
	std::cout << "\n=============Melee Attack================" << std::endl;
	frag.meleeAttack("CL4P-TP");
	std::cout << "\n=============Ranged Attack===============" << std::endl;
	frag.rangedAttack("CL4P-TP");
	std::cout << "\n=====Vaulthunter.exe (random attack)=====" << std::endl;
	frag.vaulthunter_dot_exe("CL4P-TP");
	frag.vaulthunter_dot_exe("CL4P-TP");
	frag.vaulthunter_dot_exe("CL4P-TP");
	frag.vaulthunter_dot_exe("CL4P-TP");
	frag.vaulthunter_dot_exe("CL4P-TP");
	return (0);
}