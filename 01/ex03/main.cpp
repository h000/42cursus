#include "ZombieHorde.hpp"

int	main()
{
	ZombieHorde *heap = new ZombieHorde(5);
	delete(heap);

	ZombieHorde stack = ZombieHorde(5);
	return (0);
}