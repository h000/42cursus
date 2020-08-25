#include "PowerFist.hpp"

PowerFist::PowerFist(): AWeapon("Power Fist", 8, 50){}

PowerFist::PowerFist(PowerFist const &other): AWeapon(other){}

PowerFist::~PowerFist(){}

PowerFist	&PowerFist::operator=(const PowerFist &other)
{
	this->name = other.name;
	this->apcost = other.apcost;
	this->damage = other.damage;
	return (*this);
}

void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}