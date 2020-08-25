#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	public:
		PowerFist();
		PowerFist(PowerFist const &other);
		virtual ~PowerFist();
		PowerFist	&operator=(const PowerFist &other);
		virtual void	attack() const;
};


#endif