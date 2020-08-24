#include "Victim.hpp"

Victim::Victim()
{}

Victim::Victim(std::string name) : name(name)
{
	std::cout << "Some random victim called "<< name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const &other)
{
	*this = other;
	std::cout << "Some random victim called "<< name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name
	<< " just died for no apparent reason!" << std::endl;
}

Victim	&Victim::operator=(const Victim &other)
{
	this->name = other.name;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Victim& vt)
{
	os << "I am " << vt.getName() << " and I like otters!\n";
	return (os);
}

std::string		Victim::getName(void) const
{
	return (this->name);
}

void			Victim::getPolymorphed() const
{
	std::cout << this->name <<
	" has been turned into a cute little sheep!" << std::endl;
}