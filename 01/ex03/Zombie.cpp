#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string name, std::string type)
{
	this->name = name;
	this->type = type;
}

Zombie::~Zombie(){}

void	Zombie::announce()
{
	std::cout << "<" << this->name << "(" << this->type << ")> Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::setNameAndType(std::string name, std::string type)
{
	this->name = name;
	this->type = type;
}