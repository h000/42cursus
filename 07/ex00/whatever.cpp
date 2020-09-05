/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 22:58:49 by hpark             #+#    #+#             */
/*   Updated: 2020/09/05 13:15:06 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	swap(T &first, T &second)
{
	T	tmp = first;
	first = second;
	second = tmp;
}

template <typename T>
T	min(T &first, T &second)
{
	if (first < second)
		return first;
	else
		return second;
	
}

template <typename T>
T	max(T first, T second)
{
	if (first > second)
		return first;
	else
		return second;
}

class
Awesome {
	public:
		Awesome( int n ) : _n( n ) {}
		bool operator==( Awesome const & rhs ) { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) { return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) { return (this->_n <= rhs._n); }
	private:
		int _n;
};

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	

	std::cout << "===============Awesome Test====================" << std::endl;
	Awesome aa(2);
	Awesome bb(3);
	Awesome ret(0);
	::swap(aa, bb);
	if (aa > bb)
		std::cout << "its swapped" << std::endl;
	ret = ::min(aa, bb);
	if (ret == bb)
		std::cout << "min worked" << std::endl;
	ret = ::max(aa, bb);
	if (ret == aa)
		std::cout << "max worked" << std::endl;

	return 0;
}
