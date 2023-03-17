#pragma once
#include "Product.hpp"

class Food : public Product
{
public:
	Food() : Product(), _calories(0) {}
	Food(std::string name, double price, int calories)
		: Product(name, price), _calories(calories) {}

	int getCalories() const { return _calories; }

	void setCalories(int calories) { _calories = calories; }

	void print() const override;

private:
	int _calories;
};
