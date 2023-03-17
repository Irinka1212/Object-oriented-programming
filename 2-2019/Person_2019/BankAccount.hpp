#pragma once
class BanckAccount
{
public:
	BanckAccount() : _balance(2000), _creditLimit(1000) {}
	BanckAccount(int balance, int creditLimit) : _balance(balance), _creditLimit(creditLimit) {}

	void pay(int sum);
	void import(int sum) { _balance += sum; }
	void withdraw(int sum) { _balance -= sum; }
	int reviewBalance() const { return _balance; }

protected:
	int _balance;
	int _creditLimit;
};


