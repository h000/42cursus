#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>

class	Span
{
	private:
		Span();
		std::vector<int>	ints;
		unsigned int		N;
	public:
		Span(unsigned int N);
		Span(Span const &other);
		~Span();
		Span	&operator=(Span const &other);
		void	addNumber(int n);
		int		shortestSpan(void);
		int		longestSpan(void);
		class	SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};


#endif