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
// Clear the vector CardSet. There is no input and output.
	int Num();
// Show the size of vector cardset.
// There is no input and the output is an integer.
	int HiddenNum();
// Count the number of the cards hidden. 
// There is no input and the output is an integer.
	void Append(std::string, bool);
// Add a card into the cardset and sort the vector. 
// The inputs are the string card and a boolean hidden to show whether the card is hidden. There is no output.
	std::string Display();
// Show the cardset seen by the opponent. 
// There is no input and the output is a string.
	std::string SecretDisplay();
// Print the player's card set in his own view. 
// It has no input. The output is a string of the card set in one's own view.
	bool Judge(int, std::string);
// Judge whether the player's guess is right. 
// Inputs are an integer position and a string card. The output is a boolean.
	void TurnOver(int);
// Turn over a card on a given position. 
// The input is an integer position and the output is none.
	void ForcedTurnOver();
// Turn over the first hidden card in the cardset. 
// There is no input and output.
	bool NoHidden();
// Judge whether all the cards were turned over. 
// There is no input and the output is a boolean.
	std::string Archive();
// Change the cardset into a string which is used as the cardset's archive. 
// It has no input and the output is a string.
	void Load(std::string);
// Store the data, which is received from the string, into cardset. 
// Its input is a string and there is no output.
private:
	std::vector<Card> cardset;
};


#endif
