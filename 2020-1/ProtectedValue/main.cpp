#include "ProtectedValue.h"
#include <iostream>

int main()
{

	ProtectedValue<int> a(5 , 7);
	ProtectedArray<int> b;
	b.addElement(a);
	std::cout<< b.getValue(0,9);

	std::system("pause");

	return 0;
}