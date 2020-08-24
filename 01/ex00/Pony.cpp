/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:20:22 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:20:22 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, std::string color)
{
	this->name = name;
	this->color = color;
};

Pony::~Pony(){};

std::string	Pony::getName()
{
	return (this->name);
}

std::string	Pony::getColor()
{
	return (this->color);
}

void	Pony::eat()
{
	std::cout << this->name << " is eating" << std::endl;
}

void	Pony::run()
{
	std::cout << this->name << " is running" << std::endl;
}

void	Pony::sleep()
{
	std::cout << this->name << " is sleeping" << std::endl;
}