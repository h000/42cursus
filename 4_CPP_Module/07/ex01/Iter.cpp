/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 23:12:24 by hpark             #+#    #+#             */
/*   Updated: 2020/09/05 13:15:16 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	iter(T *arr, int len, void (*func)(T&))
{
	for (int i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

template<typename T>
void print(T &t)
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

/*
class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

int main()
{
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];
	iter(tab, 5, print);
	iter(tab2, 5, print);
	return 0;
}
*/