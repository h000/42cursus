#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
}

Character::Character(Character const & other)
{
	*this = other;
}

Character::~Character()
{
	int	i = 0;

	i = 0;
	while (this->_inventory[i])
	{
		delete _inventory[i]; //delete? 아니면 그냥 0?
		this->_inventory[i] = nullptr;
		++i;
	}
}

Character			&Character::operator=(Character const & other)
{
	int	i = 0;

	i = 0;
	while (this->_inventory[i])
	{
		delete _inventory[i]; //delete? 아니면 그냥 0?
		this->_inventory[i] = nullptr;
		++i;
	}
	this->_name = other.getName();
	i = 0;
	while (other._inventory[i] != nullptr)
	{
		this->equip(other._inventory[i]->clone());
		++i;
	}
	return (*this);
}

std::string const	&Character::getName() const
{
	return (this->_name);
}
void				Character::equip(AMateria* m)
{
	if (m == nullptr || this->_equipped > 3)
		return ;
	for (int i = 0; i < this->_equipped; i++)
	{
		if (this->_inventory[i] == m)
			return ;
	}
	this->_inventory[this->_equipped++] = m;
}

void				Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->_equipped)
		return ;
	while (idx < 3)
	{
		this->_inventory[idx] = this->_inventory[idx + 1];
		++idx;
	}
	this->_inventory[idx] = nullptr;
	--this->_equipped;
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= _equipped)
		return ;
	this->_inventory[idx]->use(target);
}