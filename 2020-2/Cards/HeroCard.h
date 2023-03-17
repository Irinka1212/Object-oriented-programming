#pragma once
#include "Card.h"

class HeroCard : virtual public Card
{
public:
	HeroCard() : Card(), _attackPower(0), _deffencePower(0) {}
	HeroCard(const std::string& name, int numOfCard, int numOfImg, int attackPower, int deffencePower)
		: Card(name, numOfCard, numOfImg), _attackPower(attackPower), _deffencePower(deffencePower) {}

	int getAttackPower() const { return _attackPower; }
	int getDeffencePower() const { return _deffencePower; }

	void setAttackPower(int attackPower) { _attackPower = attackPower; }
	void setDeffencePower(int deffencePower) { _deffencePower = deffencePower; }

	void print() const override
	{
		std::cout << getName() << " " << getNumOfCard() << " " << getNumOfImg() << " " << getAttackPower() << " " << getDeffencePower() << '\n';
	}

protected:
	int _attackPower;
	int _deffencePower;
};