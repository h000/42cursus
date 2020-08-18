#include "phonebook.hpp"

Contact::Contact()
{
	this->fields[0] = "first name";
	this->fields[1] = "last name";
	this->fields[2] = "nickname";
	this->fields[3] = "login";
	this->fields[4] = "postal address";
	this->fields[5] = "email address";
	this->fields[6] = "phonebook number";
	this->fields[7] = "birthday date";
	this->fields[8] = "favorite meal";
	this->fields[9] = "underwear color";
	this->fields[10] = "darkest secret";
}

Contact::~Contact(){}

void	Contact::get_inputs(void)
{
	for(int i = 0; i < 11; i++)
	{
		std::cout << this->fields[i] << "> ";
		std::cin >> inputs[i];
		if (std::cin.eof())
		{
			std::cin.clear();
			exit(0);
		}
	}
}

void	Contact::print_overview(void)
{
	int	blank_length = 0;

	for (int i = 0; i < 3; i++)
	{
		if (this->inputs[i].length() > 10)
		{
			this->inputs[i].resize(9);
			this->inputs[i].append(".");
		}
		else
			blank_length = 10 - this->inputs[i].length();
		for (int j = 0; j < blank_length ; j++)
			std::cout << " ";
		std::cout << this->inputs[i];
		std::cout << '|';
	}
	std::cout << std::endl;
}

void	Contact::print(void)
{
	for (int i = 0; i < 11; i++)
	{
		std::cout << this->fields[i] << " : " << this->inputs[i] << std::endl;
	}
}