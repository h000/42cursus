/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:39:45 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 13:39:47 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <exception>
# include <math.h>
# include <limits.h>

enum	Type
{
	_char,
	_int,
	_float,
	_double,
	_invalid
};

class Convert
{
	private:
		Convert();
		std::string	value;
		int			type;
		double		scalar;
	public:
		Convert(std::string value);
		Convert(Convert	const &other);
		~Convert();
		Convert	&operator=(Convert const &other);
		int			getType();
		std::string	getValue();
		char		toChar() const;
		int			toInt() const;
		float		toFloat() const;
		double		toDouble() const;
		std::exception	ImpossibleException() const;
		std::exception	NonDisplayableException() const;
};

std::ostream &operator<<(std::ostream &out, Convert const &c);


#endif