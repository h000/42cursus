/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:46:15 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:47:00 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy
{
	protected:
		Enemy();
		int			hp;
		std::string	type;
	public:
		Enemy(int hp, std::string const &type);
		Enemy(Enemy const &other);
		virtual ~Enemy();
		Enemy	&operator=(const Enemy &other);
		std::string	getType() const;
		int	getHP() const;
		virtual void	takeDamage(int damage);
};


#endif