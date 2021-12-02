/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:45:53 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:47:39 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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