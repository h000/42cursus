#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>

class	Contact
{
	private:
		std::string	fields[11];
		std::string	inputs[11];
	public:
		Contact();
		void	get_inputs();
		void	print_overview();
		void	print();
		~Contact();

};

class	PhoneBook
{
	private:
		Contact	contact[8];
		int		cnt;
	public:
		PhoneBook();
		void	add_contact();
		void	search_contact();
		~PhoneBook();
};

#endif