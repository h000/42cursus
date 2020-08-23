#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>
# include <random>

class FragTrap
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
		FragTrap();
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &other);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &other);
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		vaulthunter_dot_exe(std::string const &target);
		void		minionTrap(std::string const &target);
		void		rubberDucky(std::string const &target);
		void		senselessSacrifice(std::string const &target);


};

#endif