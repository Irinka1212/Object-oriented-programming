#define _CRT_SECURE_NO_WARNINGS 1
#include "Person.hpp"
#include <cstring>
#include <iostream>

Person::Person(const char* name, int egn, int age, int year) : _name(nullptr), _egn(egn), _age(age), _year(year)
{
	if (name != nullptr)
	{
		size_t size = std::strlen(name);
		_name = new char[size+1];
		std::strncpy(_name, name, size);
		_name[size] = '\0';
	}
}
Person::Person(const Person& other)
{
	_egn = other.getEGN();
	_age = other.getAge();
	_year = other.getYear();

	size_t size = std::strlen(other.getName());
	_name = new char[size + 1];
	std::strncpy(_name, other.getName(), size);
	_name[size] = '\0';
}
Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		delete[] _name;

		_egn = other.getEGN();
		_age = other.getAge();
		_year = other.getYear();

		size_t size = std::strlen(other.getName());
		_name = new char[size + 1];
		std::strncpy(_name, other.getName(), size);
		_name[size] = '\0';
	}
	return *this;
}
Person::~Person()
{
	delete[] _name;
}
void Person::setName(const char* name)
{
	delete[] _name;

	size_t size = std::strlen(name);
	_name = new char[size + 1];
	std::strncpy(_name, name, size);
	_name[size] = '\0';
}
