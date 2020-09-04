#include "Base.hpp"

Base	*generate(void)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 2);

	switch (dis(gen))
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (0);
}

void	identify_from_pointer(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify_from_reference(Base & p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}