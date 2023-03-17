#pragma once
#include <string>
#include <vector>
#include <iostream>

class Card
{
public:
	Card() : _numOfCard(0), _numOfImg(0) {}
	Card(const std::string& name, int numOfCard, int numOfImg)
		: _name(name), _numOfCard(numOfCard) , _numOfImg(numOfImg) {}

	std::string getName() const { return _name; }
	int getNumOfCard() const { return _numOfCard; }
	int getNumOfImg() const { return _numOfImg; }

	void setName(const std::string& name) { _name = name; }
	void setNumOfCard(int numOfCard) { _numOfCard = numOfCard; }
	void setNumOfImg(int numOfImg) { _numOfImg = numOfImg; }

	virtual void print() const 
	{
		std::cout << getName() << " " << getNumOfCard() << " " << getNumOfImg() << '\n';
	}
protected:
	std::string _name;
	int _numOfCard;
	int _numOfImg;
};