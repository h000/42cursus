/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:18:35 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:18:35 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(){}

Sed::~Sed(){}

int	Sed::openFile(std::string filename)
{
	this->ifs.open(filename);
	if (!this->ifs.is_open())
		return (0);
	this->ofs.open(filename + ".replace");
	if (!this->ofs.is_open())
	{
		this->ifs.close();
		return (0);
	}
	return (1);
}

void	Sed::replace(std::string s1, std::string s2)
{
	std::string	line;

	while (std::getline(this->ifs, line))
	{
		while (line.find(s1) != std::string::npos)
			line.replace(line.find(s1), s1.length(), s2);
		this->ofs << line << std::endl;
	}
}

void	Sed::closeFile()
{
	if (this->ifs.is_open())
		this->ifs.close();

	if (this->ofs.is_open())
		this->ofs.close();
}