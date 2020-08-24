/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:20:02 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:20:03 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
