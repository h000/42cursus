/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:45:17 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:45:32 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include "Victim.hpp"

class Sorcerer
{
	private:
		std::string	name;
		std::string	title;
		Sorcerer();
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const &other);
		~Sorcerer();
		Sorcerer	&operator=(const Sorcerer &other);
		void		polymorph(Victim const &) const;
		std::string	getName(void) const;
		std::string	getTitle(void) const;
};

std::ostream& operator<<(std::ostream& out, const Sorcerer& sc);

#endif