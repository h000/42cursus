#include "ZombieEvent.hpp"

int	main()
{
	ZombieEvent	zomb;
	Zombie		*zombie1;
	Zombie		*randomZombies[3];

	zomb.setZombieType("crazy");
	zombie1 = zomb.newZombie("zombie1");
	zombie1->announce();

	for (int i = 0; i < 3; i++)
	{
		randomZombies[i] = zomb.randomChump();
		randomZombies[i]->announce();
	}

	delete(zombie1);
	for (int i = 0; i < 3; i++)
		delete(randomZombies[i]);

	Zombie	zombieStack("zoms", "dead");
	zombieStack.announce();
	return (0);
}
