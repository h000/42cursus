#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle();
		PlasmaRifle(PlasmaRifle const &other);
		virtual ~PlasmaRifle();
		PlasmaRifle	&operator=(const PlasmaRifle &other);
		virtual void	attack() const;
};


#endif