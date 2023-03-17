#pragma once
#include <string>
#include <iostream>
#include <vector>

class Product
{
public:
	Product() : _price(0.0) {}
	Product(std::string name, double price)
		: _name(name), _price(price) {}

	std::string getName() const { return _name; }
	double getPrice() const { return _price; }

	void setName(const std::string& name) { _name = name; }
	void setPrice(double price) { _price = price; }

	virtual void print() const;

protected:
	std::string _name;
	double _price;
};

