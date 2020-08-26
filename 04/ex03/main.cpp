#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
///


	AMateria* first = tmp;
	
	std::cout << "aaaaaaaaaaaaaaa" << std::endl;
	me->use(-1, *bob);
	std::cout << "materia exp: " << first->getXP() << std::endl;
	std::cout << "aaaaaaaaaaaaaaa" << std::endl;
	me->use(0, *bob);
	std::cout << "materia exp: " << first->getXP() << std::endl;
	std::cout << "aaaaaaaaaaaaaaa" << std::endl;
	me->use(1, *bob);
	std::cout << "aaaaaaaaaaaaaaa" << std::endl;
	me->use(2, *bob);
	std::cout << "aaaaaaaaaaaaaaa" << std::endl;
	me->use(3, *bob);
	std::cout << "aaaaaaaaaaaaaaa" << std::endl;
	me->use(4, *bob);
	std::cout << "aaaaaaaaaaaaaaa" << std::endl;
	me->unequip(0);
	std::cout << "materia exp: " << first->getXP() << std::endl;
	me->use(0, *bob);
	std::cout << "materia exp: " << first->getXP() << std::endl;
	me->use(3, *bob);
	me->unequip(-1);
	me->equip(first);
///
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	
	return 0;
}
