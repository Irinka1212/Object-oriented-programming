#pragma once
#include <string>
#include <vector>
#include <iostream>

class UserTemp
{
public:
	UserTemp() {};
	UserTemp(const std::string& name, const std::string& password) 
		: _name(name), _password(password) {}

	std::string getName() const { return _name; }
	std::string getPassword() const { return _password; }

	void setName(const std::string& name) { _name = name; }
	void setPassword(const std::string& password) { _password = password; }

	virtual double monthlyGain() const = 0;

protected:
	std::string _name;
	std::string _password;
};

class User : public UserTemp
{
public:
	User() : UserTemp(), _dailyGain(0.0) {}
	User(const std::string& name, const std::string& password, double dailyGain)
		: UserTemp(name,password), _dailyGain(dailyGain) {}

	double getDailyGain() const { return _dailyGain; }

	void setDailyGain(double dailyGain) { _dailyGain = dailyGain; }

	double monthlyGain() const override { return getDailyGain() * 30.416; }
protected:
	double _dailyGain;
};
class PaidUser : public UserTemp
{
public:
	PaidUser() : UserTemp(), _monthlyBill(0.0) {}
	PaidUser(const std::string& name, const std::string& password, const std::string& nameOfAbonament, double monthlyBill)
		: UserTemp(name, password), _nameOfAbonament(nameOfAbonament), _monthlyBill(monthlyBill) {}

	std::string getNameOfAbonament() const { return _nameOfAbonament; }
	double getMonthlyBill() const { return _monthlyBill; }

	void setNameOfAbonament(const std::string& nameOfAbonament) { _nameOfAbonament = nameOfAbonament; }
	void setMonthlyBill(double monthlyBill) { _monthlyBill = monthlyBill; }

	double monthlyGain() const override { return getMonthlyBill(); }
protected:
	std::string _nameOfAbonament;
	double _monthlyBill;
};
class Users 
{
public:
	void addUser(UserTemp* user)
	{
		_users.push_back(user);
	}

	void usersWithAbonament() const
	{
		double count = 0.0;
		for (int i = 0; i < _users.size(); ++i)
		{
			PaidUser* paidUser = dynamic_cast<PaidUser*>(_users[i]);
			if (paidUser)
				++count;
		}
		double persentage = (count * 100) / (_users.size());
		std::cout << persentage << '\n';

	}

	void monthlyMoney() const 
	{
		for (int i = 0; i < _users.size(); ++i)
		{
			std::cout << _users[i]->monthlyGain() << " ";
		}
	}
	void getUser(int index) const
	{
		if (index < 0 || index >= _users.size())
			return;

		for (int i = 0; i < _users.size(); ++i)
		{
			if (index == i)
			{
				std::cout << _users[i]->getName() << '\n';
			}
		}
	}
private:
	std::vector<UserTemp*> _users;
};
