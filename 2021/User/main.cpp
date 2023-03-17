#include <iostream>
#include "User.h"

int main()
{
	User a("ira", "sadadsf", 5.15);
	std::cout << a.getName() << " " << a.getPassword() << " " << a.getDailyGain() << " " << a.monthlyGain() << '\n';

	a.setName("irina");
	a.setPassword("efwef");
	a.setDailyGain(15.4);

	std::cout << a.getName() << " " << a.getPassword() << " " << a.getDailyGain() << " " << a.monthlyGain() << '\n';

	PaidUser b("stani", "akakaa", "premium", 20.20);
	std::cout << b.getName() << " " << b.getPassword() << " " << b.getNameOfAbonament() << " " << b.getMonthlyBill() << " " << b.monthlyGain() << '\n';

	b.setName("stanimir");
	b.setPassword("wedwsef");
	b.setMonthlyBill(22.22);
	b.setNameOfAbonament("gold");

	std::cout << b.getName() << " " << b.getPassword() << " " << b.getNameOfAbonament() << " " << b.getMonthlyBill() << " " << b.monthlyGain() << '\n';
	User d("ff", "ssss", 2.3);

	Users c;
	c.addUser(&a);
	c.addUser(&b);
	c.addUser(&d);

	c.getUser(1);
	c.getUser(2);
	c.getUser(0);

	c.monthlyMoney();
	std::cout << '\n';

	c.usersWithAbonament();

	std::system("pause");

	return 0;
}