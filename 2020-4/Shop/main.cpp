#include <iostream>
#include "Product.h"

int main()
{
	Food a("burger", "fgh", 12.12, 600);
	std::cout << a.getName() << " " << a.getCode() << " " << a.getPrice() << " " << a.getCalories() << '\n';

	a.setCalories(555);
	a.setName("bigmac");
	a.setCode("the");
	a.setPrice(12.78);

	std::cout << a.getName() << " " << a.getCode() << " " << a.getPrice() << " " << a.getCalories() << '\n';

	Drink b("beer", "sssss", 2.0, 2.4);
	std::cout << b.getName() << " " << b.getCode() << " " << b.getPrice() << " " << b.getABV() << '\n';

	b.setABV(1.2);
	b.setName("stela");
	b.setCode("hello");
	b.setPrice(1.78);

	std::cout << b.getName() << " " << b.getCode() << " " << b.getPrice() << " " << b.getABV() << '\n';

	Shop c;
	c.addProduct(&a);
	c.addProduct(&b);

	c.searchProduct("hello");
	c.searchProduct("the");

	c.printProductsWithLowerPrice();


	std::system("pause");

	return 0;
}