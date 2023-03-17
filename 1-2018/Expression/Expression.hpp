#pragma once
#include <iostream>

class Expression
{
public:
	virtual int value() const = 0;
	virtual void print() const = 0;
};

class Const : public Expression 
{
public:
	Const(int value);
	int value() const override { return _value; }
	void print() const override { std::cout << value(); }

protected:
	int _value;
};

class Var : public Expression
{
public:
	Var();
	Var(const char* other, int value);
	Var(const Var& other);
	Var& operator=(const Var& other);
	~Var();

	int value() const override { return _value; }
	void print() const override;

	void setValue(int value);

	const char* getExp() const { return _exp; }
	void setExp(const char* exp);
protected:
	int _value;
	char* _exp;
};

class Sum : public Expression
{
public:
	Sum() : _firstExp(nullptr), _secondExp(nullptr) {}
	Sum(Expression* firstExp, Expression* secondExp);
	Sum(const Sum& other);
	Sum& operator=(const Sum& other);
	~Sum();

	int value() const override { return _firstExp->value() + _secondExp->value(); }
	void print() const override;

	Expression* getFirstExp() const { return _firstExp; }
	Expression* getSecondExp() const { return _secondExp; }
	
protected: 
	Expression* _firstExp;
	Expression* _secondExp;

	void setup(Expression* first, Expression* second);
};
