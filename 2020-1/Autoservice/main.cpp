#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Service.hpp"

int main()
{
	Car a("Reno", "Senic", 2008, "DWSDW", low, false);
	Bus b("Mercedes", "dedde", 2002, "yhgrfdes", high, true);
	Service d;
	d.addNewVehicle(&a);
	d.addNewVehicle(&b);
	Car p("Opel", "Astra", 2004, "dwdwf", medium, true);
	d.addNewVehicle(&p);
	std::cout << d.getCapacityPoints() << '\n';
	Bus r("Fiat", "gre", 2001, "ferfgre", high, 0);

	std::cout<< d.hasCapacity(b.getState()) << '\n';
	std::cout << b.getBrand() << " " << b.getHasPassengers() << '\n';
	std::cout << a.getIsPrivate() << " " << a.getYear() << '\n';
	std::cout << p.getModel() << " " << p.getProblem() << '\n';
	std::cout << r.getState() << '\n';
	r.setBrand("BMW");
	std::cout<< r.getBrand() << '\n';
	p.setYear(1000);
	std::cout << p.getYear() << '\n';
}