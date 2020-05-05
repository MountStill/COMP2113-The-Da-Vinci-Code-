#ifndef _CARDPOOL_H_
#define _CARDPOOL_H_
#include <vector>
#include <string>


class CardPool
{
public:
	void Initialize();
	std::string Pick();
private:
	std::vector<std::string> cardpool;
};


#endif
