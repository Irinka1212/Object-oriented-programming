#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <cstring>
#include <fstream>

class Person
{
public:
	Person() : _name(nullptr) , _surname(nullptr) {}
	Person(const char* name, const char* surname);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	char* getName() const { return _name; }
	char* getSurname() const { return _surname; };

	void setName(const char* name)
	{
		copyString(_name, name);
	}
	void setSurname(const char* surname)
	{
		copyString(_surname, surname);
	}

	friend std::ostream& operator<<(std::ostream& out, const Person& other);
	friend std::istream& operator>>(std::istream& in, Person& other);

	void saveToFile(const char* nameFile);
	void copyString(char* str, const char* newStr);
private:
	char* _name;
	char* _surname;

	void copy(const Person& other);
};

Person::Person(const char* name, const char* surname)
{
	if (name != nullptr)
		copyString(_name, name);

	if (surname != nullptr)
		copyString(_surname, surname);
}

Person::Person(const Person& other)
{
	copy(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		delete[] _name;
		delete[] _surname;

		copy(other);
	}
	return *this;
}

Person::~Person()
{
	delete[] _name;
	delete[] _surname;
}

std::ostream& operator<<(std::ostream& out, const Person& other)
{
	out << other._name;
	out << other._surname;
	return out;
}

std::istream& operator>>(std::istream& in, Person& other)
{
	char buffer[100];
	in >> buffer;
	delete[] other._name;
	delete[] other._surname;

	other._name = new char[strlen(buffer) + 1];
	in >> other._name;
	std::strcpy(buffer, other._name);

	other._surname = new char[strlen(buffer) + 1];
	in >> other._surname;
	std::strcpy(buffer, other._surname);
	return in;
}
void Person::saveToFile(const char* nameFile)
{
	std::ofstream file(nameFile, std::ios::app);
	file << *this;
	file.close();

}
void Person::copyString(char* str, const char* newStr)
{
	if (str)
		delete[] str;

	size_t size = std::strlen(newStr);
	str = new char[size + 1];
	std::strncpy(str, newStr, size);
	str[size] = '\0';
}

void Person::copy(const Person& other)
{
	copyString(_name, other.getName());

	copyString(_surname, other.getSurname());
}