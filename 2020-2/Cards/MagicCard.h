#pragma once
#include "Card.h"

class MagicCard : virtual public Card
{
public:
	MagicCard() : Card() {}
	MagicCard(const std::string& name, int numOfCard, int numOfImg, const std::string& effect)
		: Card(name, numOfCard, numOfImg), _effect(effect) {}

	std::string getEffect() const { return _effect; }

	void setEffect(const std::string& effect) { _effect = effect; }

	void print() const override
	{
		std::cout << getName() << " " << getNumOfCard() << " " << getNumOfImg() << " " << getEffect() << '\n';
	}

protected:
	std::string _effect;
};