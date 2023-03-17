#pragma once
#include "HeroCard.h"
#include "MagicCard.h"

class SpecialCard : virtual public HeroCard, virtual public MagicCard
{
public:
	SpecialCard() : Card(), HeroCard(), MagicCard(), _level(0) {}
	SpecialCard(const std::string& name, int numOfCard, int numOfImg, int attackPower, int deffencePower, const std::string& effect, int level)
		: Card(name, numOfCard, numOfImg), HeroCard(name, numOfCard, numOfImg, attackPower, deffencePower), MagicCard(name, numOfCard, numOfImg, effect), _level(level) {}

	int getLevel() const { return _level; }

	void setLevel(int level) { _level = level; }

	void print() const override
	{
		std::cout << getName() << " " << getNumOfCard() << " " << getNumOfImg() << " " << getAttackPower() << " " << getDeffencePower() << " " << getEffect() << " " << getLevel() << '\n';
	}

private:
	int _level;
};