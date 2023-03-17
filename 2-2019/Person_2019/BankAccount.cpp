#include "BankAccount.hpp"
void BanckAccount::pay(int sum)
{
	if (sum <= (_balance + _creditLimit))
	{
		_balance -= sum;
	}
}
