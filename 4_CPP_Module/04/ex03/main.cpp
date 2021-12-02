/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:51:20 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:51:45 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	me->use(0, *bob);
	me->use(1, *bob);
///

	AMateria *first = tmp;
	
	std::cout << "=============" << std::endl;
	me->use(-1, *bob);
	std::cout << "materia cure exp: " << first->getXP() << std::endl;
	std::cout << "=============" << std::endl;
	me->use(0, *bob);
	std::cout << "materia cure exp: " << first->getXP() << std::endl;
	std::cout << "=============" << std::endl;
	me->use(1, *bob);
	std::cout << "materia cure exp: " << first->getXP() << std::endl;
	std::cout << "=============" << std::endl;
	me->use(2, *bob);
	std::cout << "=============" << std::endl;
	me->use(3, *bob);
	std::cout << "=============" << std::endl;
	me->use(4, *bob);
	std::cout << "=============" << std::endl;
	me->unequip(0);
	me->use(0, *bob);
	std::cout << "materia cure exp: " << first->getXP() << std::endl;
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
