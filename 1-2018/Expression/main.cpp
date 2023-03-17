#include <iostream>
#include "Expression.hpp"
void isLeapYear(long year)
{
	if (year <= 0)
		std::cout << "error\n";
	else if (year % 100 == 0)
	{
		if (year % 400 == 0)
			std::cout << "leap\n";
		else
			std::cout << " not leap\n";
	}
	else if (year % 4 == 0)
	{
		std::cout << "leap\n";
	}
	else
		std::cout << "not leap\n";
}
long long fib(long long num)
{
	if (num <= 1)
		return num;
	else
		return fib(num - 1) + fib(num - 2);

	
}
int main()
{
	Var* baby = new Var("baby", 25);
	Const* bate = new Const(16);
	Sum* a = new Sum(baby, bate);
	Sum b(bate, a);
	std::cout<< baby->getExp();
	std::cout << b.value() << '\n';
	b.print();
}