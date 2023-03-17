#pragma once
#include "Person.hpp"
#include "BankAccount.hpp"
class PersonwithAccount : public Person, public BanckAccount
{
public:
	PersonwithAccount() : Person(), BanckAccount(), _iban(0) {}
	PersonwithAccount(const char* name, int egn, int age, int year, int balance, int creditLimit, long long iban)
		: Person(name, egn, age, year), BanckAccount(balance, creditLimit), _iban(iban) {}

	long long getIBAN() const { return _iban; }
	void setIBAN(long long iban) { _iban = iban; }

	void registertoSpotify();
private:
	long long _iban;
};
