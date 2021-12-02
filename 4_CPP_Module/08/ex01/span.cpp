#include "span.hpp"

Span::Span(unsigned int N)
{
	this->N = N;
	this->ints.reserve(N);
}

Span::Span(Span const &other)
{
	*this = other;
}


Span::~Span() {}

Span	&Span::operator=(Span const &other)
{
	this->N = other.N;
	this->ints = other.ints;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->ints.size() >= this->N)
		throw SpanFullException();
	this->ints.push_back(n);
}

int		Span::shortestSpan(void)
{
	if (this->ints.size() < 2)
		throw std::out_of_range("OutOfRange: There is no span to find.");

	std::vector<int>::iterator	iter;
	std::vector<int>	v;
	int	min;

	v = this->ints;
	std::sort(v.begin(), v.end());
	iter = v.begin();
	min = std::abs(*(iter + 1) - *iter);
	iter++;
	for (; iter + 1 != v.end(); ++iter)
	{
		int	tmp = std::abs(*(iter + 1) - *iter);
		if (tmp < min)
			min = tmp;
	}
	return (min);
}

unsigned int		Span::longestSpan(void)
{
	if (this->ints.size() < 2)
		throw std::out_of_range("OutOfRange: There is no span to find.");

	int max = *std::max_element(this->ints.begin(), this->ints.end());
	int min = *std::min_element(this->ints.begin(), this->ints.end());
	return (max - min);
}

const char* Span::SpanFullException::what() const throw()
{
	return "SpanFullException: The storage is full.";
}
