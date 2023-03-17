#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "Person.hpp"
#include "BankAccount.hpp"
#include "PersonwithAccount.hpp"
int main()
{
	PersonwithAccount a("Georgi Hristov", 1212121320, 20, 2000, 789, 1000, 7894561230);
	std::cout << a.getName() << '\n';
	std::cout << a.getAge() << '\n';
	std::cout << a.getEGN() << '\n';
	std::cout << a.getIBAN() << '\n';
	std::cout << a.getYear() << '\n';
	std::cout << a.reviewBalance() << '\n';

	a.pay(100);
	a.withdraw(789);
	a.import(1000);
	a.registertoSpotify();

	a.setName("Ivan Ivanov");
	a.setAge(21);
	a.setEGN(1234567890);
	a.setYear(1998);
	a.setIBAN(7418529630);

	a.registertoSpotify();
	std::cout << a.getName() << '\n';
	std::cout << a.getAge() << '\n';
	std::cout << a.getEGN() << '\n';
	std::cout << a.getIBAN() << '\n';
	std::cout << a.getYear() << '\n';
	std::cout << a.reviewBalance() << '\n';
}