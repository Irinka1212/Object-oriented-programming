#include "Card.h"
#include "HeroCard.h"
#include "MagicCard.h"
#include "SpecialCard.h"
#include "Pack.h"
#include <iostream>
#include <vector>

int main()
{
	Card a("sakura", 5, 6);
	HeroCard b("naruto", 1, 16, 106, 999);
	MagicCard c("sasuke", 2, 12, "sharingan");
	SpecialCard d("itachi", 69, 17, 420, 420, "sharingan mangekyo", 999);

	std::cout << a.getNumOfCard() << " " << a.getNumOfImg() << " " << a.getName() << '\n';
	std::cout << b.getNumOfCard() << " " << b.getNumOfImg() << " " << b.getName() << " " << b.getAttackPower() << " " << b.getDeffencePower() << '\n';
	std::cout << c.getNumOfCard() << " " << c.getNumOfImg() << " " << c.getName() << " " << c.getEffect() << '\n';
	std::cout << d.getNumOfCard() << " " << d.getNumOfImg() << " " << d.getName() << d.getAttackPower() << " " << d.getDeffencePower()  << " " << d.getLevel() << " " << d.getEffect() <<  '\n';

	a.print();
	b.print();
	c.print();
	d.print();

	Pack f;
	f.addCard(&a);
	f.addCard(&b);
	f.addCard(&c);
	f.addCard(&d);
	f.printInfo();
	std::cout << '\n';

	/*Pack::getInstance()->addCard(a);
	Pack::getInstance()->addCard(b);
	Pack::getInstance()->addCard(c);
	Pack::getInstance()->printInfo();
	std::cout << '\n';*/

	a.setName("hurano");
	a.setNumOfCard(8);
	a.setNumOfImg(7);

	b.setAttackPower(999);
	b.setName("uzumaki");
	b.setDeffencePower(9999);
	b.setNumOfCard(106);
	b.setNumOfImg(99);

	c.setEffect("rinnegan");
	c.setName("uchiha");
	c.setNumOfCard(96);
	c.setNumOfImg(96);

	d.setLevel(555);

	std::cout << a.getNumOfCard() << " " << a.getNumOfImg() << " " << a.getName() << '\n';
	std::cout << b.getNumOfCard() << " " << b.getNumOfImg() << " " << b.getName() << " " << b.getAttackPower() << " " << b.getDeffencePower() << '\n';
	std::cout << c.getNumOfCard() << " " << c.getNumOfImg() << " " << c.getName() << " " << c.getEffect() << '\n';
	std::cout << d.getNumOfCard() << " " << d.getNumOfImg() << " " << d.getName() << d.getAttackPower() << " " << d.getDeffencePower() << " " << d.getLevel() << " " << d.getEffect() << '\n';

	a.print();
	b.print();
	c.print();
	d.print();

	f.printInfo();
	//Pack::getInstance()->printInfo();

	std::system("pause");

	return 0;
}