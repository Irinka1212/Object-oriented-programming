#pragma once
#include  <stdexcept>

template <typename T>
class ProtectedValue
{
public:
	ProtectedValue() : _code(0), _value(T()) {}
	ProtectedValue(const T& value, int code)
		: _value(value), _code(code) {}

	ProtectedValue(const ProtectedValue& other)
	{
		_value = other._value;
		_code = other._code;
	}

	T getValue(int code) const 
	{
		if (code == getCode())
		{
			return _value;
		}
		return T();
	}

	int getCode() const { return _code; }
protected:
	T _value;
	int _code;
};

template <typename T>
class ProtectedArray
{
public:
	ProtectedArray() :  _values(nullptr), _size(0) {}

	ProtectedArray(const ProtectedArray& other)
	{
		copyOther(other);
	}
	ProtectedArray& operator=(const ProtectedArray& other)
	{
		if (this != other)
		{
			copyOther(other);
		}
		return *this;
	}
	~ProtectedArray() 
	{
		delete[] _values;
	}

	int getSize() const { return _size; }

	T getValue(int index, int code) const
	{
		for (int i = 0; i < _size; ++i)
		{
			if (code == _values[index].getCode())
			{
				return _values[index].getValue(code);
			}
			else
				return T();
		}
	}

	void addElement(const ProtectedValue<T>& element)
	{
		ProtectedValue<T>* newValues = new ProtectedValue<T>[_size];
		for (int i = 0; i < _size; ++i)
		{
			newValues[i] = _values[i];
		}

		delete[] _values;

		++_size;

		_values = new ProtectedValue<T>[_size];
		for (int i = 0; i < _size - 1; ++i)
		{
			_values[i] = newValues[i];
		}
		_values[_size-1] = element;

		delete[] newValues;
	}
private:
	ProtectedValue<T>* _values;
	int _size;

	void copyOther(const ProtectedArray& other)
	{
		if (_values)
			delete[] _values;

		_size = other.getSize();

		_values = new ProtectedValue<T>[_size];
		for (int i = 0; i < _size; ++i)
		{
			_values[i] = other._values[i];
		}
	}
};