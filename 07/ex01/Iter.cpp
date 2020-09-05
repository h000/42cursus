/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 23:12:24 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 23:12:26 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	iter(T *arr, int len, void func(T&))
{
	for (int i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

template<typename T>
void print(T const &t)
{
    std::cout << t << std::endl;
}

template<typename T>
void multiple(T &a)
{
	std::cout << a * 2 << std::endl;
}

int main()
{
	int	intArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string	strArr[] = {"aa", "bb", "cc", "dd", "ee", "ff", "gg"};

	iter<const int>(intArr, 10, print);
	iter<const std::string>(strArr, 7, print);

	iter<int>(intArr, 10, multiple);

	return (0);
}
