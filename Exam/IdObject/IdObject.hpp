#pragma once
#include <stdexcept>
template <typename T>
class IdObject
{
public:
	IdObject() : _object(T()), _id(0) {}
	IdObject(const T& object, int id)
		: _object(object), _id(id) {}

	IdObject(const IdObject& other)
	{
		_object = other._object;
		_id = other._id;
	}

	T getObject() const	{	return T();}
	int getID() const { return _id; }

	bool operator==(IdObject<T>& other);
	bool operator!=(IdObject<T>& other);
	bool operator>(IdObject<T>& other)
	{
		return (getID() > other.getID());
	}
	bool operator<(IdObject<T>& other)
	{
		return (getID() < other.getID());
	}
private:
	T _object;
	int _id;
};

