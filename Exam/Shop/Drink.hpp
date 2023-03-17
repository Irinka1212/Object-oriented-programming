#pragma once
#include "Product.hpp"

class Drink : public Product
{
public:
	Drink() : Product(), _quantity(0.0) {}
	Drink(std::string name, double price, double quantity)
		: Product(name, price), _quantity(quantity) {}

	double getQuantity() const { return _quantity; }

	void setQuantity(double quantity) { _quantity = quantity; }

	void print() const override;

private:
	double _quantity;
};
