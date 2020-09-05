#include "Array.hpp"
#include <iostream>

int	main()
{
	std::cout << "\n==========if array is empty===============" << std::endl;
	Array<int> t;
	std::cout << t.size();
	std::cout << "\n===================int=====================" << std::endl;
	Array<int> test(10);
	for(int i = 0; i < 10; i++)
	{
		test[i] = i;
		std::cout << test[i] << " ";
	}
	std::cout << "\n===================char=====================" << std::endl;
	Array<char> ch(10);
	for (int i = 0; i < 10; i++)
	{
		ch[i] = 'a' + i;
		std::cout << ch[i] << " ";
	}
	std::cout << "\n================copy constructor===================" << std::endl;
	Array<int> test2(test);
	std::cout << "==== test2 ====" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		std::cout << test2[i] << " ";
	}
	test2[0] = 100;
	std::cout << "\n===============" << std::endl;
	for(int i = 1; i < 10; i++)
		test2[i] = i;
	for(int i = 0; i < 10; i++)
		std::cout << test2[i] << " ";
	std::cout << std::endl;
	std::cout << "====deep copy====" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		std::cout << test[i] << " ";
	}
	std::cout << "\n====================assignation====================" << std::endl;
	Array<int> test3;
	test3 = test2;
	std::cout << "==== test3 ====" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		std::cout << test3[i] << " ";
	}
	std::cout << "\n===============" << std::endl;
	test3[0] = 10000;
	for(int i = 1; i < 10; i++)
		test3[i] = i;
	for(int i = 0; i < 10; i++)
		std::cout << test3[i] << " ";
	std::cout << std::endl;
	std::cout << "====deep copy====" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		std::cout << test2[i] << " ";
	}
	std::cout << "\n==================== default constructor ===============" << std::endl;
	Array<int> test4;
	try
	{
		test4[0];
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}