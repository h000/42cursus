/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:49:26 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:49:55 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad
{
	private:
		typedef struct	s_units
		{
			ISpaceMarine	*unit;
			struct s_units	*next;
		}				t_units;
		int				count;
		t_units			*units;
	public:
		Squad();
		Squad(Squad const &other);
		virtual ~Squad();
		Squad	&operator=(const Squad &other);
		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int idx) const;
		virtual int push(ISpaceMarine* unit);
};

#endif