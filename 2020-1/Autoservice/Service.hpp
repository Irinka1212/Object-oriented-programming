#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Vehicle.h"

class Service
{
public:
	Service() : _capacityPoints(0) {}
	int getCapacityPoints() const { return _capacityPoints; }
	std::vector<Vehicle*> getVehicles() const { return _vehicles; }

	bool hasCapacity(State state) const
	{
		return (_capacityPoints + state) <= 10;
	}
	void addNewVehicle(Vehicle* newVehicle)
	{
		if (hasCapacity(newVehicle->getState()))
		{
			_vehicles.push_back(newVehicle);
			_capacityPoints += newVehicle->getState();
		}
	}

private:
	int _capacityPoints;
	std::vector<Vehicle*> _vehicles;
};