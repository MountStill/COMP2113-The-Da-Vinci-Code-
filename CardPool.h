#ifndef _CARDPOOL_H_
#define _CARDPOOL_H_
#include <vector>
#include <string>


class CardPool
{
public:
	void Initialize();
// Initialize the cardpool with all cards placed in it at the beginning.
// There is no input and output
	bool Empty();
// Judge whether the vector is empty.
// There is no input and the output is a boolean.
	std::string Pick();
// Randomly pick a card from the carpool and output the card as a string. 
// There is no input and the output is a string
	std::string Archive();
// Display the cardpool as a string and it can be used as the cardpool archive.
// It has no input and the output is a string.
	void Load(std::string);
// Store the data received from the string into cardpool. 
// It's input is a string and there is no output.
private:
	std::vector<std::string> cardpool;
};


#endif
