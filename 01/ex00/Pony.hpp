#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony
{
	private:
		std::string	name;
		std::string	color;
	public:
		Pony(std::string name, std::string color);
		std::string	getName(void);
		std::string	getColor(void);
		void	eat(void);
		void	run(void);
		void	sleep(void);
		~Pony();
};

#endif