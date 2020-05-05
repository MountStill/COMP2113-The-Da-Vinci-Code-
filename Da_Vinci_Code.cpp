#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "CardSet.h"
#include "CardPool.h"
using namespace std;

struct Player
{
	string palyername;
	CardSet cardset;
};

void SetDifficulty(double &prob_comp);


int main()
{
	double prob_comp;
	SetDifficulty(prob_comp);
	CardPool cardpool;   
	cardpool.Initialize();



}


void SetDifficulty(double &prob_comp)
{
	string difficulty_level;
	ifstream initiator("Initiator.txt");
	initiator >> difficulty_level;
	if (difficulty_level == "EASY")
	{
		prob_comp = 0.1;
	}
	else if (difficulty_level == "NORMAL")
	{
		prob_comp = 0.3;
	}
	else if (difficulty_level == "HARD")
	{
		prob_comp = 0.5;
	}
	else if (difficulty_level == "EXPERT")
	{
		prob_comp = 0.8;
	}
	else if (difficulty_level == "HELL")
	{
		prob_comp = 1.0;
	}
}
