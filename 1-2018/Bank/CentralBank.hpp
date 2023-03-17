#pragma once
#include <string>
#include <vector>
#include <iostream>

struct Currency 
{
	std::string name;
	double rate;
};

class Observer
{
public:
	virtual void update(const Currency& c) const = 0;
};
class ConcreteObserver : public Observer
{
public:
	void update(const Currency& c) const
	{
		std::cout << "Update(" << _name << " " << c.name << " " << c.rate << '\n';
	}
private:
	std::string _name;
};

class CentralBank
{
private:
	std::string _name;

	std::vector<Currency> _currencies;
	std::vector<Observer*> _observers;
public:
	CentralBank() {}
	CentralBank(const std::string& name) { _name = name; }
	
	void addCurrency(const Currency& c) 
	{
		/*for (int i = 0; i < _currencies.size(); ++i)
		{
			if (_currencies[i].name.compare(c.name) == 0)
				return;
		}*/
		_currencies.push_back(c);
	}
	void deleteCurrency(const Currency& c)
	{
		for (int i = 0; i < _currencies.size(); ++i)
		{
			if (_currencies[i].name.compare(c.name) == 0)
			{
				_currencies.erase(_currencies.begin() + i);
				return;
			}
		}
	}
	void notify(int index) const
	{
		for (int i = 0; i < _observers.size(); ++i)
		{
			_observers[i]->update(_currencies[index]);
		}
	}

	void setRate(const Currency& c)
	{ 
		for (int i = 0; i < _currencies.size(); ++i)
		{
			if (_currencies[i].name.compare(c.name) == 0)
			{
				_currencies[i].rate = c.rate;
				notify(i);
				return;
			}
		}
	}

	void registerObserver(Observer* ob)
	{
		_observers.push_back(ob);
	}
	void unregisterObserver(Observer* ob)
	{
		for (int i = 0; i < _observers.size(); ++i)
		{
			if (_observers[i]== ob)
			{
				_observers.erase(_observers.begin() + i);
				return;
			}
		}
	}
};

