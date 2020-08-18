#include "phonebook.hpp"

int	main()
{
	std::string	input;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "command> ";
		std::cin >> input;
		if (input.compare("ADD") == 0)
			phonebook.add_contact();
		else if (input.compare("SEARCH") == 0)
			phonebook.search_contact();
		else if (input.compare("EXIT") == 0)
			; //나가기
		else if (std::cin.eof())
			break ; //ctrl + D
		else
			continue ; //필요 없음		
	}
	return (0);
}