#pragma once
#include "Product.hpp"
#include "Drink.hpp"
#include "Food.hpp"

class Shop
{
public:
	Shop() {};
	std::vector<Product*> getProducts() const { return _products; }

	void addDrink(Drink* newDrink);
	void addFood(Food* newFood);

	void getProduct(int index) const;
	void printAll() const;
private:
	std::vector<Product*> _products;
};