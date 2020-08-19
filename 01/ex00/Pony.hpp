#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony
{
	private:
		char	*name;
		char	*color;
	public:
		Pony(/* args */);
		~Pony();
};

Pony::Pony(/* args */){}
Pony::~Pony(){}

void	ponyOnTheHeap();
void	ponyOnTheStack();


#endif