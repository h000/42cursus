/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:19:29 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:19:29 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){}

Brain::~Brain(){}

std::string	Brain::identify()
{
	Brain				*address = this;
	std::stringstream	ss;

	ss << address;
	return (ss.str());
}