/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:20:39 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:20:40 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
	if (this->cnt == 0)
		return ;
	for (int i = 0; i < cnt; i++)
	{
		std::cout << "|         " << i << "|";
		this->contact[i].print_overview();
	}
	std::cout << "index> ";
	while (!(std::cin >> idx) || idx < 0 || idx > this->cnt - 1)
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Invalid Index" << std::endl;
		std::cout << "index> ";
		if (std::cin.eof())
			exit(0);
	}
	std::cin.ignore(256, '\n');
	this->contact[idx].print();
}