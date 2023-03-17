#pragma once
#include "Vehicle.h"

class Bus : public Vehicle
{
public:
	Bus(const std::string& brand, const std::string& model, int year, const std::string& problem, State state, bool hasPassengers)
		: Vehicle(brand, model, year, problem, state), _hasPassengers(hasPassengers) {}

	bool getHasPassengers() const { return _hasPassengers; }
	void setHasPassengers(bool hasPassengers) { _hasPassengers = hasPassengers; }
private:
	bool _hasPassengers;
};