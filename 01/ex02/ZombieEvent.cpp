/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:20:10 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:20:11 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(){}

ZombieEvent::~ZombieEvent(){}

void	ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	Zombie	*zombie;
	
	zombie = new Zombie(name, this->type);
	return (zombie);
}

Zombie	*ZombieEvent::randomChump()
{
	std::string	names[5] = {"zom1", "zom2", "zom3", "zom4", "zom5"};

	Zombie *zombie;
	
	zombie = new Zombie(names[rand() % 5], this->type);
	return (zombie);
}
