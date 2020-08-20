#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

class	ZombieEvent
{
	private:
		std::string name;
		std::string type;
	public:
		ZombieEvent();
		void	setZombieType(std::string type);
		Zombie	*newZombie(std::string name);
		Zombie	*randomChump();
		~ZombieEvent();
};

#endif
