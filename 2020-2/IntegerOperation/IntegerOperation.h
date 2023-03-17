#pragma once
#include <cstring>

class IntegerOperation
{
public:
	IntegerOperation() : _numbers(nullptr), _result(0), _size(0) {}
	IntegerOperation(const IntegerOperation& other);
	IntegerOperation& operator=(const IntegerOperation& other);
	~IntegerOperation();
	
	int* getNumbers() const { return _numbers; }
	int getResult() const { return _result; }
	int getSize() const { return _size; }

	void insert(int num);

	void sum();
	void sub();
	void multiply();

	int operator+(IntegerOperation& other);
	int operator-(IntegerOperation& other);
	int operator*(IntegerOperation& other);

private:
	int* _numbers;
	int _result;
	int _size;

	void copyFrom(const IntegerOperation& other);
};
IntegerOperation::IntegerOperation(const IntegerOperation& other)
{
	copyFrom(other);
}

IntegerOperation& IntegerOperation::operator=(const IntegerOperation& other)
{
	if (this != &other)
	{
		delete[] _numbers;

		copyFrom(other);
	}
	return *this;
}

IntegerOperation::~IntegerOperation()
{
	delete[] _numbers;
}

void IntegerOperation::insert(int num)
{
	int* newNumbers = new int[_size];
	for (int i = 0; i < _size; ++i)
	{
		newNumbers[i] = _numbers[i];
	}
	delete[] _numbers;

	++_size;

	_numbers = new int[_size];
	for (int i = 0; i < _size-1; ++i)
	{
		_numbers[i] = newNumbers[i];
	}
	_numbers[_size - 1] = num;

	delete[] newNumbers;

}
void IntegerOperation::sum()
{
	_result = 0;
	for (size_t i = 0; i < _size; ++i)
	{
		_result += _numbers[i];
	}
}
void IntegerOperation::sub()
{
	_result = 0;
	for (size_t i = 0; i < _size; ++i)
	{
		_result -= _numbers[i];
	}
}
void IntegerOperation::multiply()
{
	_result = 1;
	for (size_t i = 0; i < _size; ++i)
	{
		_result *= _numbers[i];
	}
}
int IntegerOperation::operator+(IntegerOperation& other)
{
	sum();
	other.sum();
	return getResult() + other.getResult();
}

int IntegerOperation::operator-(IntegerOperation& other)
{
	sub();
	other.sub();
	return getResult() - other.getResult();
}

int IntegerOperation::operator*(IntegerOperation& other)
{
	multiply();
	other.multiply();
	return getResult() * other.getResult();
}

void IntegerOperation::copyFrom(const IntegerOperation& other) 
{
	_size = other._size;
	_result = other._result;
	_numbers = new int[_size + 1];
	for (size_t i = 0; i < other._size; ++i)
	{
		_numbers[i] = other._numbers[i];
	}
}