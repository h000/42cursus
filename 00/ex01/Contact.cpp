#include "PhoneBook.hpp"

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
	for (int i = 0; i < 11; i++)
	{
		std::cout << this->fields[i] << "> ";
		std::getline(std::cin, inputs[i]);
		if (std::cin.eof())
		{
			std::cin.clear();
			exit(0);
		}
	}
}

void	Contact::print_overview(void)
{
	 std::string str;

	for (int i = 0; i < 3; i++)
	{
		if (this->inputs[i].length() > 10)
			str = this->inputs[i].substr(0, 9).append(".");
		else
		{
			str.assign(10 - this->inputs[i].length(), ' ');
 			str.append(this->inputs[i]);
		}
		
		std::cout << str;
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