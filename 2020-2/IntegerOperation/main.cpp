#include<iostream>
#include"IntegerOperation.h"

int main() 
{
	IntegerOperation test;
	test.insert(5);
	test.insert(3);
	test.insert(7);

	test.sum();
	std::cout << test.getResult() << '\n';

	test.sub();
	std::cout << test.getResult() << '\n';

	test.multiply();
	std::cout << test.getResult() << '\n';

	IntegerOperation test2;
	test2.insert(2);
	test2.insert(14);
	test2.insert(4);

	std::cout << test + test2 << '\n';
	std::cout << test - test2 << '\n';
	std::cout << test * test2 << '\n';
	
	std::system("pause");
	return 0;
}