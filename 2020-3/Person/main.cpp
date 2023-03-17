#include "Person.h"

int main()
{
	Person a("Irina", "Hristova");
	Person b("Stanimir", "Hristov");

	a.saveToFile("Ira");
	a.saveToFile("Stankata");

	std::system("pause");
	return 0;
}