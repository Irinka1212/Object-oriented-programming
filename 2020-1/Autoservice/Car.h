#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car(const std::string& brand, const std::string& model, int year, const std::string& problem, State state, bool isPrivate)
		: Vehicle(brand, model, year, problem, state), _isPrivate(isPrivate) {}

	bool getIsPrivate() const { return _isPrivate; }
	void setIsPrivate(bool isPrivate) { _isPrivate = isPrivate; }
private:
	bool _isPrivate;
};