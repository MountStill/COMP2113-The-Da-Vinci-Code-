#include "CardSet.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

bool cmp(Card& x, Card& y)
{
	return x.card < y.card;
}

void CardSet::Initialize()
{
	cardset.clear();
}

int CardSet::HiddenNum()
{
	int num = 0;
	for (int i = 0; i < cardset.size(); i++)
	{
		if (cardset[i].card_hidden == 1)
		{
			num += 1;
		}
	}
	return num;
}

void CardSet::Append(string card, bool hidden)
{
	cardset.push_back({ card, hidden });
	sort(cardset.begin(), cardset.end(), cmp);
}

string CardSet::Display()
{
	string display;
	for (int i = 0; i < cardset.size(); i++)
	{
		if (cardset[i].card_hidden == 1)
		{
			display += ("XX" + cardset[i].card.substr(2, 1) + " ");
		}
		else if (cardset[i].card_hidden == 0)
		{
			display += (cardset[i].card + " ");
		}
	}
	return display;
}

string CardSet::SecretDisplay()
{
	string display;
	for (int i = 0; i < cardset.size(); i++)
	{
		display += (cardset[i].card + " ");
	}
	return display;
}

bool CardSet::Judge(int position, string card)
{
	if (cardset[position].card == card)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void CardSet::TurnOver(int position)
{
	cardset[position].card_hidden = 0;
}

void CardSet::ForcedTurnOver()
{
	for (int i = 0; i < cardset.size(); i++)
	{
		if (cardset[i].card_hidden == 1)
		{
			cardset[i].card_hidden = 0;
			break;
		}
	}
}

bool CardSet::NoHidden()
{
	int num = 0;
	for (int i = 0; i < cardset.size(); i++)
	{
		if (cardset[i].card_hidden == 1)
		{
			num += 1;
		}
	}
	if (num == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

string CardSet::Archive()
{
	string archive;
	for (int i = 0; i < cardset.size(); i++)
	{
		archive += (cardset[i].card + " ");
		archive += (to_string(cardset[i].card_hidden) + " ");
	}
	return archive;
}



void CardSet::Load(string s)
{
	istringstream iss(s);
	string number;
	bool hidden;
	cardset.clear();
	while (iss >> number)
	{
		iss >> hidden;
		cardset.push_back({ number, hidden });
	}
}
