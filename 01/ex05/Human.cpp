/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:19:33 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:19:33 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(){}

Human::~Human(){}

Brain		&Human::getBrain()
{
	return (this->brain);
}

std::string	Human::identify()
{
	return (this->brain.identify());
}