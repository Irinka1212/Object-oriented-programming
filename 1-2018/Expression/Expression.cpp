#define _CRT_SECURE_NO_WARNINGS 1 

#include "Expression.hpp"
#include <cstring>
#include <iostream>

Var::Var() : _value(0), _exp(nullptr) {}

Var::Var(const char* exp, int value) : Expression(), _value(value), _exp(nullptr)
{
	if (exp != nullptr)
	{
		size_t size = std::strlen(exp);
		_exp = new char[size + 1];
		std::strncpy(_exp, exp, size);
		_exp[size] = '\0';
	}
}

Var::Var(const Var& other)
{
	_value = other.value();
	size_t size = std::strlen(other.getExp());
	_exp = new char[size + 1];
	std::strncpy(_exp, other.getExp(), size);
	_exp[size] = '\0';
}
Var& Var::operator=(const Var& other)
{
	if (this != &other)
	{
		delete[] _exp;

		_value = other.value();
		size_t size = std::strlen(other.getExp());
		_exp = new char[size+1];
		std::strncpy(_exp, other.getExp(), size);
		_exp[size] = '\0';
	}
	return *this;
}
Var::~Var()
{
	if (_exp != nullptr)
		delete[] _exp;
}

void Var::print() const
{
	std::cout << _exp;
	
}
void Var::setValue(int value)
{
	_value = value;
}

void Var::setExp(const char* exp)
{
	delete[] _exp;

	size_t size = std::strlen(exp);
	_exp = new char[size+1];
	std::strncpy(_exp, exp, size);
	_exp[size] = '\0';
}

Const::Const(int value) : _value(value) {}

Sum::Sum(Expression* firstExp, Expression* secondExp) 
{
	setup(firstExp, secondExp);
}
Sum::Sum(const Sum& other)
{
	setup(other.getFirstExp(), other.getSecondExp());
}

Sum& Sum::operator=(const Sum& other)
{
	if (this != &other)
	{
		delete _firstExp;
		delete _secondExp;

		setup(other.getFirstExp(), other.getSecondExp());
	}

	return *this;
}
Sum::~Sum()
{
	delete _firstExp;
	delete _secondExp;
}

void Sum::print() const 
{
	if (_firstExp != nullptr && _secondExp != nullptr)
	{
		std::cout << "(";
		_firstExp->print();
		std::cout << "+";
		_secondExp->print();
		std::cout<< ")";
	}
}
void Sum::setup(Expression* firstExp, Expression* secondExp)
{
	Var* firstVar = dynamic_cast<Var*>(firstExp);
	Const* firstConst = dynamic_cast<Const*>(firstExp);
	Sum* firstSum = dynamic_cast<Sum*>(firstExp);

	Var* secondVar = dynamic_cast<Var*>(secondExp);
	Const* secondConst = dynamic_cast<Const*>(secondExp);
	Sum* secondSum = dynamic_cast<Sum*>(secondExp);

	if (firstVar)
	{
		_firstExp = new Var(*firstVar);
	}
	else if (firstConst)
	{
		_firstExp = new Const(*firstConst);
	}
	else if (firstSum)
	{
		_firstExp = new Sum(*firstSum);
	}
	if (secondVar)
	{
		_secondExp = new Var(*secondVar);
	}
	else if (secondConst)
	{
		_secondExp = new Const(*secondConst);
	}
	else if (secondSum)
	{
		_secondExp = new Sum(*secondSum);
	}
}