/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:19:59 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:19:59 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class	ZombieHorde
{
	private:
		int		N;
		Zombie	*zombies;
	public:
		ZombieHorde(int N);
		void	announce();
		~ZombieHorde();
};


#endif