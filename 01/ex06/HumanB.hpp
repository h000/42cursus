/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:18:55 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:18:55 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string		name;
		Weapon		*weapon;
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack();
		~HumanB();
};

#endif