#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("A", 149);
		std::cout << a;
		a.decrementGrade();
		std::cout << a;
		a.decrementGrade();
		std::cout << a;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("B", 2);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
		b.incrementGrade();
	}
	catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
	try
	{
		Bureaucrat c("C", 155);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		 Bureaucrat d("D", -24);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}