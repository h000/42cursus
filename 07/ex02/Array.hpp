#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

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