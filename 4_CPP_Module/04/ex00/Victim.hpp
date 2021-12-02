/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:45:29 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 15:47:47 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{
	protected:
		std::string	name;
		Victim();
	public:
		Victim(std::string name);
		Victim(Victim const &other);
		virtual ~Victim();
		Victim	&operator=(const Victim &other);
		virtual void	getPolymorphed() const;
		std::string	getName(void) const;
};

std::ostream& operator<<(std::ostream& out, const Victim& vt);

#endif