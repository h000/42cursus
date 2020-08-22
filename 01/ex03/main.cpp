#include "ZombieHorde.hpp"

int	main()
{
	ZombieHorde *heap = new ZombieHorde(5);
	heap->announce();
	delete(heap);

	ZombieHorde stack = ZombieHorde(5);
	stack.announce();
	return (0);
}