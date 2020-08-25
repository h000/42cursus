#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main()
{
	Character* me = new Character("me");
	
	std::cout << *me;

	Enemy* b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	std::cout << "\n=====new enemy SuperMutant======\n" << std::endl;
	Enemy* s = new SuperMutant();
	std::cout << "The type is " << s->getType() << std::endl;
	std::cout << "supermutant s's HP is " << s->getHP() << std::endl;

	me->equip(pf);
	std::cout << *me;
	me->attack(s);
	std::cout << *me;
	std::cout << "supermutant s's HP is " << s->getHP() << std::endl;
	me->attack(s);
	std::cout << *me;
	std::cout << "supermutant s's HP is " << s->getHP() << std::endl;

	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;

	me->attack(s);
	std::cout << *me;
	std::cout << "supermutant s's HP is " << s->getHP() << std::endl;
	me->attack(s);
	std::cout << *me;

	delete me;
	delete pr;
	delete pf;
	return 0;
}