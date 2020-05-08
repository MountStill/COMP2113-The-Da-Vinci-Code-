#ifndef _CARDPOOL_H_
#define _CARDPOOL_H_
#include <vector>
#include <string>


class CardPool
{
public:
	void Initialize();
	bool Empty();
	std::string Pick();
	std::string Archive();
	void Load(std::string);
	std::string Display();
private:
	std::vector<std::string> cardpool;
};


#endif
