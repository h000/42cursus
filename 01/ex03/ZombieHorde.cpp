#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	std::string	names[10] = {"zom1", "zom2", "zom3", "zom4", "zom5" \
	, "zom6", "zom7", "zom8", "zom9", "zom10"};

	this->zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		this->zombies[i].setNameAndType(names[rand() % 10], "dead");
	}
}

ZombieHorde::~ZombieHorde(){}