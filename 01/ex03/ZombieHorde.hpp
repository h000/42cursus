#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class	ZombieHorde
{
	private:
		int		N;
		Zombie	*zombies;
	public:
		ZombieHorde(int N);
		void	announce();
		~ZombieHorde();
};


#endif