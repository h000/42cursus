#ifndef CHARACTER_HPP
# define CHARACTER_HPP

//# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		Character();
		std::string	_name;
		int			_equipped;
		AMateria	*_inventory[4];
	public:
		Character(std::string name);
		Character(Character const & other);
		virtual ~Character();
		Character	&operator=(Character const & other);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif