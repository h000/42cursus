/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:17:37 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:17:38 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"
# include <random>

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &other);
		virtual ~FragTrap();
		FragTrap	&operator=(const FragTrap &other);
		void		vaulthunter_dot_exe(std::string const &target);
		void		minionTrap(std::string const &target);
		void		rubberDucky(std::string const &target);
		void		senselessSacrifice(std::string const &target);


};

#endif