#include <iostream>
#include <stack>
#include <list>
#include <vector>

int main(void)
{
	// list<int> lst((unsigned int)3, 100);

	std::cout << "=====constructor==========" << std::endl;
	std::list<int> mylist (3,100);          // deque with 3 elements

	std::stack<int> first;                    // empty stack
	// std::stack<int> second (mylist);         // stack initialized to copy of deque

	std::cout << "size of first: " << first.size() << '\n';
	// std::cout << "size of second: " << second.size() << '\n';

	std::cout << "=====empty==========" << std::endl;
	std::stack<int> mystack;
	int sum(0);

	for (int i=1;i<=10;i++) mystack.push(i);
	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	std::cout << "total: " << sum << '\n';

	std::cout << "=====size==========" << std::endl;
	std::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

	std::cout << "=====top==========" << std::endl;
	std::stack<int> mystack1;
	mystack1.push(10);
	mystack1.push(20);

	mystack1.top() -= 5;

	std::cout << "mystack.top() is now " << mystack1.top() << '\n';
	
	std::cout << "=====push and pop==========" << std::endl;
	std::stack<int> mystack2;

	for (int i=0; i<5; ++i) mystack2.push(i);

	std::cout << "Popping out elements...";
	while (!mystack2.empty())
	{
		std::cout << ' ' << mystack2.top();
		mystack2.pop();
	}
	std::cout << '\n';

	std::cout << "===========relational operators===========" << std::endl;
	
	if (mystack1 == mystack2)
		std::cout << "mystack1 == mystack2" << std::endl;
	if (mystack1 != mystack2)
		std::cout << "mystack1 != mystack2" << std::endl;
	if (mystack1 >= mystack2)
		std::cout << "mystack1 >= mystack2" << std::endl;
	if (mystack1 <= mystack2)
		std::cout << "mystack1 <= mystack2" << std::endl;
	if (mystack1 > mystack2)
		std::cout << "mystack1 >= mystack2" << std::endl;
	if (mystack1 < mystack2)
		std::cout << "mystack1 <= mystack2" << std::endl;
	
	std::cout << "===============================" << std::endl;
	
	return (0);
}