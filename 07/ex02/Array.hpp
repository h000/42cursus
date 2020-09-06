/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 13:16:05 by hpark             #+#    #+#             */
/*   Updated: 2020/09/05 13:16:06 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array
{
	private:
		T				*arr;
		unsigned int	len;
	public:
		Array();
		Array(unsigned int n);
		Array(Array<T> const & other);
		~Array();
		Array<T>	&operator=(Array<T> const & other);
		T		&operator[](unsigned int idx);
		std::exception	OutOfLimitsException() const;
		unsigned int	size(void) const;
};

# include "Array.tpp"

#endif