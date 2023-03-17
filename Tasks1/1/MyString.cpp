#include <iostream>
#include <cstring>
#include "MyString.h"

MyString::MyString(const char* str)
{
	if (str != NULL)
	{
		_size = std::strlen(str);
		_str = new char[_size];
		if (_str != NULL)
			std::strncpy(_str, str, _size);
	}
}

MyString::MyString(const MyString& other)
{
	copy(other);
}

MyString::~MyString()
{
	if (_str != NULL)
		delete[] _str;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		delete[] _str;
		copy(other);
	}

	return *this;
}

size_t MyString::size() const
{
	return _size;
}

void MyString::print() const
{
	if (_str != NULL)
	{
		for (size_t i = 0; i < _size; ++i)
			std::cout << _str[i];
		std::cout << '\n';
	}
}

const char* MyString::get() const
{
	return _str;
}

void MyString::append(char c)
{
	if (_str != NULL)
	{
		size_t newSize = _size + 1;
		char* newStr = new char[newSize];

		std::strncpy(newStr, _str, _size);
		newStr[_size] = c;

		delete[] _str;
		_size = newSize;
		_str = newStr;
	}
}

int MyString::compare(const MyString& other) const
{
	size_t otherSize = other.size();
	const char* otherStr = other.get();
	for (size_t i = 0; i < _size || i < otherSize; ++i)
	{
		if (_str[i] > otherStr[i])
			return 1;

		if (_str[i] < otherStr[i])
			return -1;
	}

	if (_size > otherSize)
		return 1;

	if (_size < otherSize)
		return -1;

	return 0;
}

bool MyString::operator==(const MyString& other)
{
	return 0 == compare(other);
}

bool MyString::operator!=(const MyString& other)
{
	return !(*this == other);
}

bool MyString::operator>(const MyString& other)
{
	return 1 == compare(other);
}

bool MyString::operator<(const MyString& other)
{
	return -1 == compare(other);
}

void MyString::copy(const MyString& other)
{
	_size = other.size();
	_str = new char[_size];
	std::strncpy(_str, other.get(), _size);
}