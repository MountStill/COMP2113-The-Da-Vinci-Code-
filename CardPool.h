#ifndef _CARDPOOL_H_
#define _CARDPOOL_H_
#include <vector>
#include <string>


class CardPool
{
public:
	void Initialize();
//Initialize the cardpool with all cards placed in it at the beginning.
	bool Empty();
//Judge whether the vector is empty.
	std::string Pick();
// Randomly pick a card from the carpool and output the card as a string. 
	std::string Archive();
//Display the cardpool as a string and it can be used as the cardpool archive.
	void Load(std::string);
//Store the data received from the string into cardpool. 
private:
	std::vector<std::string> cardpool;
};


#endif
