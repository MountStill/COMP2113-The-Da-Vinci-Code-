#include "CardSet.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(Card &x, Card &y)
{
	return x.card < y.card;
}

void CardSet::Initialize()
{
	cardset.clear();
}

void CardSet::Append(string card)
{
	cardset.push_back({card, 1});
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

bool CardSet::Judge(int position, string card)
{
	bool judge;
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
