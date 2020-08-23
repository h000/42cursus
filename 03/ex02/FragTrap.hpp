#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"
# include <random>

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &other);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &other);
		void		vaulthunter_dot_exe(std::string const &target);
		void		minionTrap(std::string const &target);
		void		rubberDucky(std::string const &target);
		void		senselessSacrifice(std::string const &target);


};

#endif