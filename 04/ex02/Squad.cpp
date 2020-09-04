#include "Squad.hpp"

Squad::Squad() : count(0), units(nullptr){}

Squad::Squad(Squad const &other)
{
	this->count = 0;
	for (int i = 0; i < other.count; i++)
	{
		this->push(other.getUnit(i)->clone());
	}
}

Squad::~Squad()
{
	t_units	*tmp;

	for (int i = 0; i < this->count; i++)
	{
		delete this->units->unit;
		tmp = this->units;
		this->units = this->units->next;
		delete tmp;
	}
	this->units = 0;
	this->count = 0;
}

Squad			&Squad::operator=(const Squad &other)
{
	t_units	*tmp;

	for (int i = 0; i < this->count; i++)
	{
		delete this->units->unit;
		tmp = this->units;
		this->units = this->units->next;
		delete tmp;
	}
	this->count = 0;
	for (int i = 0; i < other.count; i++)
	{
		this->push(other.getUnit(i)->clone());
	}
	return (*this);
}

int				Squad::getCount() const
{
	return (this->count);
}

ISpaceMarine*	Squad::getUnit(int idx) const
{
	t_units	*tmp;

	if (idx >= this->count || idx < 0)
		return (nullptr);
	tmp = this->units;
	for (int i = 0; i < idx; i++)
		tmp = tmp->next;
	return (tmp->unit);
}

int				Squad::push(ISpaceMarine* marine)
{
	t_units	*tmp;

	if (marine == 0)
		return (this->count);
	if (this->units == 0)
	{
		this->units = new t_units;
		this->units->unit = marine;
		this->units->next = nullptr;
		return (++this->count);
	}
	tmp = this->units;
	for (int i = 0; i < this->count - 1; i++)
	{
		if (marine == tmp->unit)
			return (this->count);
		tmp = tmp->next;
	}
	if (marine == tmp->unit)
			return (this->count);
	tmp->next = new t_units;
	tmp->next->unit = marine;
	tmp->next->next = nullptr;
	return (++this->count);
}