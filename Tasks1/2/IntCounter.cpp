#include "IntCounter.h"

IntCounter::IntCounter(int* num) : _num(num)
{
	_count = new int(1);
}

IntCounter::IntCounter(const IntCounter& other)
{
	copy(other);
}

IntCounter::~IntCounter()
{
	decreaseRef();
}

IntCounter& IntCounter::operator=(const IntCounter& other)
{
	if (this != &other)
	{
		decreaseRef();
		copy(other);
	}

	return *this;
}

void IntCounter::copy(const IntCounter& other)
{
	_num = other.getValue();
	_count = &(other.getCount());
	++(*_count);
}

void IntCounter::decreaseRef()
{
	--(*_count);
	if (0 == _count)
	{
		delete _num;
		delete _count;
	}
}