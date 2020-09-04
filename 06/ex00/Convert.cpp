/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:39:42 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 13:39:43 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(std::string value) : value(value), scalar(0)
{
	int	i = 0;
	int	len = value.length();

	if (len == 1 && !std::isdigit(value[0]))
	{
		this->type = _char;
		this->scalar = this->value[0];
		return ;
	}
	if (value == "-inff" || value == "+inff" || value == "nanf")
	{
		this->type = _float;
		this->scalar = stod(this->value);
		return ;
	}
	if (value == "-inf" || value == "+inf" || value == "nan")
	{
		this->type = _double;
		this->scalar = stod(this->value);
		return ;
	}
	if (value[0] == '+' || value[0] == '-')
		i++;
	for ( ; i < len; i++)
	{
		if (value[i] == '.' && this->type != _double)
			this->type = _double;
		else if (value[i] == 'f' && i == len - 1 && this->type == _double)
			this->type = _float;
		else if (std::isdigit(value[i]))
			continue;
		else
		{
			this->type = _invalid;
			return ;
		}
	}
	if (this->type != _double && this->type != _float)
		this->type = _int;
	this->scalar = stod(this->value);
}

Convert::Convert(Convert const &other)
{
	*this = other;
}

Convert::~Convert(){}

Convert	&Convert::operator=(Convert const &other)
{
	this->value = other.value;
	this->type = other.type;
	return (*this);
}

int	Convert::getType()
{
	return (this->type);
}

std::string	Convert::getValue()
{
	return (this->value);
}

char	Convert::toChar() const
{
	if (this->type == _invalid)
		throw ImpossibleException();
	else if (this->scalar > 127 || this->scalar < -128)
		throw ImpossibleException();
	else if (isnan(this->scalar) || isinf(this->scalar))
		throw ImpossibleException();
	else if (this->scalar > 126 || this->scalar < 32)
		throw NonDisplayableException();
	return (static_cast<char>(this->scalar));
}

int		Convert::toInt() const
{
	if (this->type == _invalid)
		throw ImpossibleException();
	if (isnan(this->scalar) || isinf(this->scalar) || this->scalar > INT_MAX || this->scalar < INT_MIN)
		throw ImpossibleException();
	return (static_cast<int>(this->scalar));
}
float	Convert::toFloat() const
{
	if (this->type == _invalid)
		throw ImpossibleException();
	return (static_cast<float>(this->scalar));
}
double	Convert::toDouble() const
{
	if (this->type == _invalid)
		throw ImpossibleException();
	return (static_cast<double>(this->scalar));
}

std::exception Convert::ImpossibleException() const
{
	throw std::invalid_argument("impossible");
}

std::exception Convert::NonDisplayableException() const
{
	throw std::invalid_argument("Non displayable");
}


std::ostream &operator<<(std::ostream &os, Convert const &convert)
{
	char	c;
	int		i;
	double	d;
	float	f;

	try
	{
		os << "char: ";
		c = convert.toChar();
		os << "'" << c << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		os << e.what() << std::endl;
	}
	try
	{
		os << "int: ";
		i = convert.toInt();
		os << i << std::endl;
	}
	catch(const std::exception& e)
	{
		os << e.what() << std::endl;
	}
	try
	{
		os << "float: ";
		f = convert.toFloat();
		os << f;
		if (fabs(f - round(f)) < 0.0001)
			os << ".0";
		os << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		os << e.what() << std::endl;
	}
	try
	{
		os << "double: ";
		d = convert.toDouble();
		os << d;
		if (fabs(d - round(d)) < 0.0001)
			std::cout << ".0" << std::endl;
	}
	catch(const std::exception& e)
	{
		os << e.what() << std::endl;
	}
	return (os);
}