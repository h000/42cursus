#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "================객체 생성================" << std::endl;
	ScavTrap	Scav("SC4V");
	std::cout << "\n=======Take damage and Be repaired=======" << std::endl;
	Scav.takeDamage(24);
	Scav.beRepaired(50);
	Scav.takeDamage(42);
	Scav.takeDamage(100);
	Scav.beRepaired(125);
	std::cout << "\n=============Melee Attack================" << std::endl;
	Scav.meleeAttack("CL4P-TP");
	std::cout << "\n=============Ranged Attack===============" << std::endl;
	Scav.rangedAttack("CL4P-TP");
	std::cout << "\n=======Challenge Newcomer (random)=======" << std::endl;
	Scav.challengeNewcomer();
	return (0);
}