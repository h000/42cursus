/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:46:05 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:47:35 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
		Character();
		std::string	name;
		int	ap;
		AWeapon	*weapon;
	public:
		Character(std::string const &name);
		Character(Character const &other);
		~Character();
		Character	&operator=(const Character &other);
		void recoverAP();
		void equip(AWeapon * weapon);
		void attack(Enemy * enemy);
		std::string	getName() const;
		int			getAP() const;
		AWeapon		*getAWeapon() const;
};

std::ostream& operator<<(std::ostream& os, const Character& c);

#endif