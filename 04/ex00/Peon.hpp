#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
	private:
		Peon();
	public:
		Peon(std::string name);
		Peon(Peon const &other);
		virtual ~Peon();
		Peon	&operator=(const Peon &other);
		virtual void	getPolymorphed() const;
};


#endif