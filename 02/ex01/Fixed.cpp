/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:20:55 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:20:56 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	// this->value = other.getRawBits();
}

Fixed::Fixed(const int N)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = N << fractionalBits;
}

Fixed::Fixed(const float F)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = (round(F * (1 << fractionalBits)));
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation constructor called" << std::endl;
	this->value = other.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (value >> fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
	os << fx.toFloat();
	return (os);
}