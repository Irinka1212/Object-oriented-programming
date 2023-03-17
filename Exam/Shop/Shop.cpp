#include "Shop.hpp"

void Shop::addDrink(Drink* newDrink)
{
	_products.push_back(newDrink);
}

void Shop::addFood(Food* newFood)
{
	_products.push_back(newFood);
}

void Shop::getProduct(int index) const
{
	if (index < 0 || index >= _products.size())
		return;

	for (int i = 0; i < _products.size(); ++i)
	{
		if (index == i)
		{
			std::cout << _products[index]->getName() << '\n';
		}
	}
}
void Shop::printAll() const
{
	for (int i = 0; i < _products.size(); ++i)
	{
		_products[i]->print();
	}
}