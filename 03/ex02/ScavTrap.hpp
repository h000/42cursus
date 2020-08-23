#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"
# include <random>

class ScavTrap
{
	private:
		unsigned int	HP;
		unsigned int	maxHP;
		unsigned int	EP;
		unsigned int	maxEP;
		unsigned int	lv;
		std::string	name;
		int	meleeAttackDamage;
		int	rangedAttackDamage;
		int	armorDamageReduction;
	public:
		ScavTrap();
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &other);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &other);
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		challengeNewcomer();
};


#endif