#pragma once
#include <iostream>
#include <string>
#include <vector>

class Product
{
public:
	Product() :  _price(0.0) {}
	Product(const std::string& name, const std::string& code, double price)
		: _name(name), _code(code), _price(price) {}

	std::string getName()const { return _name; }
	std::string getCode() const { return _code; }
	double getPrice() const { return _price; }

	void setName(const std::string& name) { _name = name; }
	void setCode(const std::string& code) { _code = code; }
	void setPrice(double price) { _price = price; }

protected:
	std::string _name;
	std::string _code;
	double _price;
};

class Food : public Product
{
public:
	Food() : Product() , _calories(0) {}
	Food(const std::string& name, const std::string& code, double price, int calories)
		: Product(name,code,price), _calories(calories) {}

	int getCalories() const { return _calories; }

	void setCalories(int calories) { _calories = calories; }

private:
	int _calories;
};

class Drink : public Product
{
public:
	Drink() : Product(), _abv(0) {}
	Drink(const std::string& name, const std::string& code, double price, double abv)
		: Product(name, code, price), _abv(abv) {}

	double getABV() const { return _abv; }

	void setABV(double abv) { _abv = abv; }
private:
	double _abv;//alcoholpercentage
};

class Shop 
{
public:
	Shop() {};
	std::vector<Product*> getProducts() const { return _products;}

	void addProduct(Product* newProduct)
	{
		_products.push_back(newProduct);
	}

	void removeProduct(const std::string& code)
	{
		for (int i = 0; i < _products.size(); ++i)
		{
			if (code == _products[i]->getCode())
			{
				_products.erase(_products.begin() + i);
				return;
			}
		}
	}

	void printProductsWithLowerPrice()
	{
		double price;
		std::cin >> price;

		for (int i = 0; i < _products.size(); ++i)
		{
			if (_products[i]->getPrice() < price)
			{
				std::cout << _products[i]->getName() << " ";
			}
		}
	}

	void searchProduct(const std::string& code)
	{
		for (int i = 0; i < _products.size(); ++i)
		{
			if (code ==_products[i]->getCode())
			{
				std::cout << _products[i]->getName() << " ";
			}
		}
	}
private:
	std::vector<Product*> _products;
};
