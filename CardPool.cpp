#include "CardPool.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;


void CardPool::Initialize()
{
	cardpool.clear();
	cardpool = { "00B", "01B", "02B", "03B", "04B", "05B", "06B", "07B", "08B", \
	"09B", "10B", "11B", "00W", "01W", "02W", "03W", "04W", "05W", "06W", "07W", "08W", \
	"09W", "10W", "11W" };
}

bool CardPool::Empty()
{
	if (cardpool.size() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

string CardPool::Pick()
{
	int poolsize = cardpool.size();
	srand((unsigned int)(time(0)));
	int pickorder = rand() % poolsize;
	string pickcard = cardpool[pickorder];
	cardpool.erase(cardpool.begin() + pickorder);
	return pickcard;
}

string CardPool::Archive()
{
	string archive;
	for (int i = 0; i < cardpool.size(); i++)
	{
		archive += (cardpool[i] + " ");
	}
	return archive;
}

void CardPool::Load(string str)
{
	istringstream iss(str);
	string card;
	cardpool.clear();
	while (iss >> card)
	{
		cardpool.push_back(card);
	}
}
