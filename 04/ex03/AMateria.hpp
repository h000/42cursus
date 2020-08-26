#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
	protected:
		AMateria();
		std::string	_type;
		unsigned int _xp;
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const &other);
		virtual ~AMateria();
		AMateria	&operator=(AMateria const &other);
		std::string const & getType() const;
		unsigned int getXP() const;
		virtual void use(ICharacter& target);
};


#endif