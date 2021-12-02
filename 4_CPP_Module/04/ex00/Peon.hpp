/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:44:56 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:45:08 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
	private:
		Peon();
	public:
		Peon(std::string name);
		Peon(Peon const &other);
		virtual ~Peon();
		Peon	&operator=(const Peon &other);
		virtual void	getPolymorphed() const;
};


#endif