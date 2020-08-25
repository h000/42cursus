#include "Character.hpp"

Character::Character(std::string const &name):
name(name), ap(40), weapon(NULL){}

Character::Character(Character const &other)
{
	*this = other;
}

Character::~Character(){}

Character	&Character::operator=(const Character &other)
{
	this->name = other.name;
	this->ap = other.ap;
	this->weapon = other.weapon;
	return (*this);
}

void		Character::recoverAP()
{
	this->ap += 10;
	if (this->ap > 40)
		this->ap = 40;
}

void		Character::equip(AWeapon * weapon)
{
	this->weapon = weapon;
}

void		Character::attack(Enemy * enemy)
{
	if (!this->weapon || !enemy)
		return ;
	if (this->ap < this->weapon->getAPCost())
		return ;
	std::cout << this->name << " attacks " << enemy->getType()
	<< " with a " << this->weapon->getName() << std::endl;
	this->ap -= this->weapon->getAPCost();
	this->weapon->attack();
	enemy->takeDamage(this->weapon->getDamage());
	if (enemy->getHP() <= 0)
		delete enemy;
}

std::string	Character::getName() const
{
	return (this->name);
}

int			Character::getAP() const
{
	return (this->ap);
}

AWeapon		*Character::getAWeapon() const
{
	return (this->weapon);
}

std::ostream& operator<<(std::ostream& os, const Character& c)
{
	if (c.getAWeapon())
		os << c.getName() << " has " << c.getAP()
		<< " AP and wields a " << c.getAWeapon()->getName() << std::endl;
	else
		os << c.getName() << " has " << c.getAP()
		<< " AP and is unarmed" << std::endl;
	return (os);
}