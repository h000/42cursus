#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{
	protected:
		AWeapon();
		std::string	name;
		int			apcost;
		int			damage;
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const &other);
		virtual ~AWeapon();
		AWeapon	&operator=(const AWeapon &other);
		std::string	getName() const;
		int	getAPCost() const;
		int	getDamage() const;
		virtual void	attack() const = 0;
};


#endif