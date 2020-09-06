#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
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
};


#endif