#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <algorithm>
# include <iostream>
# include <stdexcept>

template <typename T>
int	easyfind(T &first, int second)
{
	auto p = find(first.begin(), first.end(), second);
	if (p != first.end())
		return (*p);
	else
		throw std::out_of_range("Cannot be found!");
	return (-1);
}


#endif