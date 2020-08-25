#ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	public:
		SuperMutant();
		SuperMutant(SuperMutant const &other);
		virtual ~SuperMutant();
		SuperMutant	&operator=(const SuperMutant &other);
		virtual void	takeDamage(int damage);
};


#endif