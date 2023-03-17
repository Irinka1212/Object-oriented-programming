#include "Drink.hpp"

void Drink:: print() const 
{
	std::cout << getName() << " " << getPrice() << " " << getQuantity() << '\n';
}