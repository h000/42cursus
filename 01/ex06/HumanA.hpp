/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:18:49 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:18:49 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string		name;
		Weapon	&weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack();
		~HumanA();
};


#endif