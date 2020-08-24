/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:17:08 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 13:37:14 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP

# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
	public:
		SuperTrap();
		SuperTrap(std::string const &name);
		SuperTrap(SuperTrap const &other);
		virtual ~SuperTrap();
		SuperTrap	&operator=(const SuperTrap &other);
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
};


#endif
