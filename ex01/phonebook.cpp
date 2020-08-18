#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->cnt = 0;
};

PhoneBook::~PhoneBook(){}

void	PhoneBook::add_contact(void)
{
	if (this->cnt >= 8)
		{
			std::cout << "Phone book is full" << std::endl;
			return ;
		}
		this->contact[this->cnt].get_inputs();
		this->cnt++;
		std::cout << "Added" << std::endl;
}

void	PhoneBook::search_contact(void)
{
	int	idx;

	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < cnt; i++)
	{
		std::cout << "|         " << i << "|";
		this->contact[i].print_overview();
	}
	std::cout << "index> ";
	while (!(std::cin >> idx) || idx < 0 || idx > this->cnt)
	{
		std::cout << "Invalid Index\n";
	}
	this->contact[idx].print();
}