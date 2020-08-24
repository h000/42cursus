#include "Sorcerer.hpp"
#include "Peon.hpp"

int	main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	std::cout << robert << jim;
	robert.polymorph(jim);
	robert.polymorph(joe);

	std::cout << "=========================" << std::endl;
	std::cout << "Additional Tests" << std::endl;
	std::cout << "========================" << std::endl;
	Sorcerer tmp(robert);
	Victim x(jim);
	Peon y(joe);
	std::cout << tmp << x << y;
	x = jim;
	tmp.polymorph(x);
	x.getPolymorphed();
	tmp = robert;
	y = joe;
	tmp.polymorph(y);
	y.getPolymorphed();

	return 0;
}