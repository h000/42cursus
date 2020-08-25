#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	std::cout << "\n============more units============\n" << std::endl;
	ISpaceMarine* lol = new TacticalMarine;
	ISpaceMarine* pop = new TacticalMarine;
	ISpaceMarine* kim = new AssaultTerminator;
	ISpaceMarine* lim = new AssaultTerminator;

	ISquad* sqd = new Squad;
	sqd->push(lol);
	std::cout << sqd->getCount() << std::endl;
	sqd->push(kim);
	std::cout << sqd->getCount() << std::endl;
	sqd->push(pop);
	std::cout << sqd->getCount() << std::endl;
	sqd->push(lim);
	std::cout << sqd->getCount() << std::endl;
	for (int i = 0; i < sqd->getCount(); ++i)
	{
		ISpaceMarine* tmp = sqd->getUnit(i);
		tmp->battleCry();
		tmp->rangedAttack();
		tmp->meleeAttack();
	}
	delete sqd;
	return 0;
}