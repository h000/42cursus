#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*pointer = &str;
	std::string	&reference = str;

	std::cout << str << std::endl;
	std::cout << pointer << std::endl;
	std::cout << *pointer << std::endl;
	std::cout << reference << std::endl;

	str = "hello";

	std::cout << str << std::endl;
	std::cout << pointer << std::endl;
	std::cout << *pointer << std::endl;
	std::cout << reference << std::endl;

	reference = "reference";

	std::cout << str << std::endl;
	std::cout << pointer << std::endl;
	std::cout << *pointer << std::endl;
	std::cout << reference << std::endl;

	*pointer = "pointer";

	std::cout << str << std::endl;
	std::cout << pointer << std::endl;
	std::cout << *pointer << std::endl;
	std::cout << reference << std::endl;
}