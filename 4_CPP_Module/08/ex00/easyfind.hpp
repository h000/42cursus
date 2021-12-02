#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <algorithm>
# include <iostream>
# include <stdexcept>

template <typename T>
int	easyfind(T &first, int second)
{
	std::vector<int>::iterator it;
	it = find(first.begin(), first.end(), second);
	if (it != first.end())
		return (*it);
	else
		throw std::out_of_range("Cannot be found!");
	return (-1);
}


#endif