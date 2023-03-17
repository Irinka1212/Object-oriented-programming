#include <iostream>
#include "CentralBank.hpp"

int main()
{
	CentralBank a("dsk");
	Currency c;
	c.name = "lv";
	c.rate = 0.5;
	a.addCurrency(c);
	Currency d;
	d.name = "euro";
	d.rate = 0.9;
	a.addCurrency(d);
	ConcreteObserver ab;
	ConcreteObserver bc;
	ConcreteObserver cd;
	a.registerObserver(&ab);
	a.registerObserver(&bc);
	a.registerObserver(&cd);
	a.setRate(c);
	a.unregisterObserver(&cd);
	a.setRate(d);12
}