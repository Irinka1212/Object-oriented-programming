#pragma once

class IntCounter
{
public:
	IntCounter(int* num);
	IntCounter(const IntCounter& other);
	~IntCounter();
	IntCounter& operator=(const IntCounter& other);

	int* getValue() const { return _num; }
	int& getCount() const { return *_count; }

private:
	int* _num;
	int* _count;

	void copy(const IntCounter& other);
	void decreaseRef();
};
