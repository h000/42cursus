#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	std::cout << easyfind(v, 1) << std::endl;
	std::cout << easyfind(v, 2) << std::endl;
	std::cout << easyfind(v, 3) << std::endl;
	std::cout << easyfind(v, 4) << std::endl;
	try
	{
		std::cout << easyfind(v, -2) << std::endl;
	}
	catch (std::out_of_range const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}