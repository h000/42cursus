#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>

class FragTrap
{
	private:
		int	hitPoints;
		int	maxHitPoints;
		int	energyPoints;
		int	maxEnergyPoints;
		int	lv;
		std::string	name;
		int	meleeAttackDamage;
		int	armorDamageReduction;
	public:
		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);


};

#endif