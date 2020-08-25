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