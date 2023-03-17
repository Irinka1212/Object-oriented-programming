#include "Food.hpp"

void Food::print() const 
{
	std::cout << getName() << " " << getPrice() << " " << getCalories() << '\n';
}