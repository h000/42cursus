#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type): hp(hp), type(type){}

Enemy::Enemy(Enemy const &other)
{
	*this = other;
}

Enemy::~Enemy(){}

Enemy	&Enemy::operator=(const Enemy &other)
{
	this->type = other.type;
	this->hp = other.hp;
	return (*this);
}

std::string	Enemy::getType() const
{
	return (this->type);
}

int	Enemy::getHP() const
{
	return (this->hp);
}

void	Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return ;
	if (this->hp > 0)
		this->hp -= damage;
	if (this->hp < 0)
		this->hp = 0;
}
