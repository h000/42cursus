#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(): AWeapon("Plasma Rifle", 5, 21){}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &other): AWeapon(other){}

PlasmaRifle::~PlasmaRifle(){}

PlasmaRifle	&PlasmaRifle::operator=(const PlasmaRifle &other)
{
	this->name = other.name;
	this->apcost = other.apcost;
	this->damage = other.damage;
	return (*this);
}

void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouu *" << std::endl;
}