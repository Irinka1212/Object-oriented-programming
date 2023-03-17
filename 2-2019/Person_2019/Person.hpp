#pragma once
#include <cstring>
#include <iostream>

class Person
{
public:
	Person() : _name(nullptr), _egn(0), _age(0), _year(0) {}
	Person(const Person& other);
	Person(const char* name, int egn, int age, int year);
	Person& operator=(const Person& other);
	~Person();

	const char* getName() const { return _name; }
	int getEGN() const { return _egn; }
	int getAge() const { return _age; }
	int getYear() const { return _year; }

	void setName(const char* name);
	void setEGN(int egn) { _egn = egn; }
	void setAge(int age) { _age = age; }
	void setYear(int year) { _year = year; }

protected:
	char* _name;
	int _egn;
	int _age;
	int _year;
};