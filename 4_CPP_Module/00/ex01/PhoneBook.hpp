/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:20:41 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:20:42 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

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