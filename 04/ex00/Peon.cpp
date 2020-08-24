#include "Peon.hpp"

Peon::Peon()
{}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &other) : Victim(other)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon	&Peon::operator=(const Peon &other)
{
	this->name = other.name;
	return (*this);
}

void			Peon::getPolymorphed() const
{
	std::cout << this->name <<
	" has been turned into a pink pony!" << std::endl;
}