#include "Brain.hpp"

Brain::Brain(){}

Brain::~Brain(){}

std::string	Brain::identify()
{
	Brain				*address = this;
	std::stringstream	ss;

	ss << address;
	return (ss.str());
}