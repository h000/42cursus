#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{
	protected:
		std::string	name;
		Victim();
	public:
		Victim(std::string name);
		Victim(Victim const &other);
		~Victim();
		Victim	&operator=(const Victim &other);
		virtual void	getPolymorphed() const;
		std::string	getName(void) const;
};

std::ostream& operator<<(std::ostream& out, const Victim& vt);

#endif