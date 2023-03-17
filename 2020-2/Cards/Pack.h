#pragma once
#include "Card.h"
class Pack
{
public:
	/* Static access method. */
	//static Pack* getInstance();
	//Pack() : _cards(std::vector<Card>()) {}
	Pack() {};
	std::vector<Card*> getCards() const { return _cards; }

	void addCard(Card* newCard)
	{
		_cards.push_back(newCard);
	}

	void printInfo()
	{
		for (int i = 0; i < _cards.size(); ++i)
			_cards[i]->print();
	}

private:
	/* Private constructor to prevent instancing. */
	//Pack();

	std::vector<Card*> _cards;
};