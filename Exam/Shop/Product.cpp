#include "Product.hpp"

void Product:: print() const
{
	std::cout << getName() << " " << getPrice() << '\n';
}