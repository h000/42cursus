/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:17:42 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:17:43 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		unsigned int	HP;
		unsigned int	maxHP;
		unsigned int	EP;
		unsigned int	maxEP;
		unsigned int	lv;
		std::string	name;
		int	meleeAttackDamage;
		int	rangedAttackDamage;
		int	armorDamageReduction;
	public:
		ClapTrap();
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &other);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &other);
		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);


};
#endif