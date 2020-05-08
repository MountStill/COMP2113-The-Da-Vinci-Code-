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
	int Num();
	int HiddenNum();
	void Append(std::string, bool);
	std::string Display();
	std::string SecretDisplay();
	bool Judge(int, std::string);
	void TurnOver(int);
	void ForcedTurnOver();
	bool NoHidden();
	std::string Archive();
	void Load(std::string);
	
private:
	std::vector<Card> cardset;
};


#endif
