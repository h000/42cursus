/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:53:06 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 12:53:22 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a("A", 50);
	Bureaucrat b("B", 1);
	std::cout << a;
	std::cout << b << std::endl;

	Form x("X", 70, 70);
	std::cout << x << std::endl;
	
	Form y("Y", 40, 40);
	std::cout << y << std::endl;

	std::cout << "=====X is signed by A======" << std::endl;;
	x.beSigned(a);
	std::cout << x << std::endl;

	std::cout << "=====Y is signed by A?======" << std::endl;
	try
	{
		y.beSigned(a);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n=====already signed form======" << std::endl;
	try
	{  
		x.beSigned(b);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=====try sign From X========" << std::endl;
	a.signForm(x);
	b.signForm(x);

	std::cout << "\n=====try sign Form Y========" << std::endl;
	a.signForm(y);
	b.signForm(y);
	b.signForm(y);


	return (0);
}