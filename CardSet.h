#ifndef _CARDSET_H_
#define _CARDSET_H_
#include <vector>
#include <string>

struct Card
{
	std::string card;
	bool card_hidden;
};

class CardSet
{
public:
	void Initialize();
	void Append(std::string);
	std::string Display();
	bool Judge(int, std::string);
	void TurnOver(int);
private:
	std::vector<Card> cardset;
};


#endif
