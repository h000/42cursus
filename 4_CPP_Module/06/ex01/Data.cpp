/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 22:08:44 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 22:08:45 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void	*serialize(void)
{
	static std::string	alphanum = "0123456789abcdefghijklmopqrstuvxyzABCDEFGHIJKLMOPQRSTUVXYZ";
	static int			len = alphanum.length();
	char	*raw = new char[20];

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, len - 1);
	std::uniform_int_distribution<int> dist(0, 50000);

	for (int i = 0; i < 8; i++)
	{
		raw[i] = alphanum[dis(gen)];
	}
	*reinterpret_cast<int *>(raw + 8) = dist(gen);
	for (int i = 12; i < 20; i++)
	{
		raw[i] = alphanum[dis(gen)];
	}
	return (raw);
}

Data	*deserialize(void *raw)
{
	Data *data = new Data;

	data->s1 = std::string(static_cast<char*>(raw), 8);
	data->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 8);
	data->s2 = std::string(static_cast<char*>(raw) + 12, 8);
	return (data);
}