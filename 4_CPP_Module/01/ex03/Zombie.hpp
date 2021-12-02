/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:19:55 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:19:55 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private:
		std::string name;
		std::string type;
	public:
		Zombie();
		Zombie(std::string name, std::string type);
		void	announce();
		void	setNameAndType(std::string name, std::string type);
		~Zombie();
};

#endif
