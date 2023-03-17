#pragma once
#include "IdObject.hpp"
template <typename T>
class IdObjectContainer
{
public:
	IdObjectContainer() : _objects(nullptr), _size(0) {}

	IdObjectContainer(const IdObjectContainer& other)
	{
		copyOther(other);
	}
	IdObjectContainer& operator=(const IdObjectContainer& other)
	{
		if (this != other)
		{
			copyOther(other);
		}
		return *this;
	}
	~IdObjectContainer()
	{
		delete[] _objects;
	}

	int getSize() const { return _size; }

	void addObject(const IdObject<T>& object)
	{
		IdObject<T>* newObjects = new IdObject<T>[_size];
		for (int i = 0; i < _size; ++i)
		{
			newObjects[i] = _objects[i];
		}

		delete[] _objects;

		++_size;

		_objects = new IdObject<T>[_size];
		for (int i = 0; i < _size - 1; ++i)
		{
			_objects[i] = newObjects[i];
		}
		_objects[_size - 1] = object;

		delete[] newObjects;
	}

	T operator[](int index) const
	{
		for (int i = 0; i < _size; ++i)
		{
			if (index == i)
			{
				return _objects[index].getObject();
			}
			else
				throw std::out_of_range;
		}
	}

	int operator==(IdObjectContainer<T>& other);
private:
	IdObject<T>* _objects;
	int _size;

	void copyOther(const IdObjectContainer& other)
	{
		if (_objects)
			delete[] _objects;

		_size = other.getSize();

		_objects = new IdObject<T>[_size];
		for (int i = 0; i < _size; ++i)
		{
			_objects[i] = other._objects[i];
		}
	}
};