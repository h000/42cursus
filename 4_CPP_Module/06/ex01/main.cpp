/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 22:08:51 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 22:08:52 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main(void)
{
	void *res = serialize();
	Data* data = deserialize(res);

	std::cout <<"s1: " << data->s1 << std::endl;
	std::cout <<"s2: " << data->s2 << std::endl;
	std::cout <<"n: " << data->n << std::endl;

	delete static_cast<char *>(res);
	delete data;
	return (0);
}