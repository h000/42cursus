#include "PhoneBook.hpp"

int	main()
{
	std::string	input;
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "command> ";
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			phonebook.add_contact();
		else if (input.compare("SEARCH") == 0)
			phonebook.search_contact();
		else if (input.compare("EXIT") == 0)
			exit(0);
		else if (std::cin.eof())
			break ;
		input = "";
	}
	return (0);
}