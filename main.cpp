#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "CardSet.h"
#include "CardPool.h"
using namespace std;

struct Player
{
	string playername;
	CardSet cardset;
};

void NewOrLoadGame(CardPool& cardpool, double& prob_comp, Player p[], int& turn);
// choose to start a new game or continue the last game and finish the settings.
void SetDifficulty(double& prob_comp);
// choose the game difficulty.
void LoadGameProgress(CardPool& cardpool, double& prob_comp, Player p[], int& turn);
// input the progress of the last game.
void GamePlay(CardPool& cardpool, double& prob_comp, Player p[], int& turn);
// gameplaying.
bool GameOver(Player p[], CardPool cardpool);
// judge whether one of the player's card are all turned over.
void OutputGameProgress(CardPool& cardpool, double& prob_comp, Player p[], int& turn);
// output the progress into Progress.txt when the game is paused.
void OutputSummary(Player p[], CardPool cardpool, int turn);
// output the summary results of each player in the game.

int main()
{
	CardPool cardpool;
	Player p[2];
	double probcomp = 0;
	int turn = 1;
	string command;
	p[1].playername = "Computer";
	NewOrLoadGame(cardpool, probcomp, p, turn);
	cout << setw(8) << p[0].playername << ": " << p[0].cardset.Display() << endl;
	cout << setw(8) << p[0].playername << ": " << p[0].cardset.SecretDisplay() << endl;
	cout << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;
	while (1)
	{
		cout << "This is turn " << turn << "." << endl;
		cout << "Continue the game? (Y/N)" << endl;
		cin >> command;
		while (command != "Y" && command != "N")
		{
			cout << "Please enter \"Y\" or \"N\"." << endl;
			cin >> command;
		}
		if (command == "Y")
		{
			if (GameOver(p, cardpool))
			{
				OutputSummary(p, cardpool, turn);
				break;
			}
			else
			{
				GamePlay(cardpool, probcomp, p, turn);
			}
		}
		else if (command == "N")
		{
			OutputGameProgress(cardpool, probcomp, p, turn);
			break;
		}
	}
}


void SetDifficulty(double& probcomp)
{
	string difficulty_level;
	cout << "Please choose the difficulty level. (EASY/NORMAL/HARD/EXPERT/HELL)" << endl;
	cin >> difficulty_level;
	while (difficulty_level != "EASY" && difficulty_level != "NORMAL" && difficulty_level != "HARD" && difficulty_level != "EXPERT" && difficulty_level != "HELL" )
	{
		cout << "Please input \"EASY\"/\"NORMAL\"/\"HARD\"/\"EXPERT\"/\"HELL\"! " << endl;
	}
	if (difficulty_level == "EASY")
	{
		probcomp = 0.1;
	}
	else if (difficulty_level == "NORMAL")
	{
		probcomp = 0.3;
	}
	else if (difficulty_level == "HARD")
	{
		probcomp = 0.5;
	}
	else if (difficulty_level == "EXPERT")
	{
		probcomp = 0.8;
	}
	else if (difficulty_level == "HELL")
	{
		probcomp = 1.0;
	}
}

void NewOrLoadGame(CardPool& cardpool, double& prob_comp, Player p[], int& turn)
{
	string command;
	cout << "Start a new game? (Y/N)" << endl;
	cin >> command;
	while (command != "Y" && command != "N")
	{
		cout << "Please input \"Y\" or \"N\"! " << endl;
		cin >> command;
	}
	if (command == "Y")
	{
		cout << "New game starts." << endl;
		cout << "Please enter your name. (No more than 8 characters.)" << endl;
		cin >> p[0].playername;
		SetDifficulty(prob_comp);
		cardpool.Initialize();
		p[0].cardset.Initialize();
		p[1].cardset.Initialize();
		for (int i = 0; i < 4; i++)
		{
			p[0].cardset.Append(cardpool.Pick(), 1);
		}
		for (int i = 0; i < 4; i++)
		{
			p[1].cardset.Append(cardpool.Pick(), 1);
		}
	}
	else if (command == "N")
	{
		LoadGameProgress(cardpool, prob_comp, p, turn);
		cout << "Last game is loaded." << endl;
	}
}

void LoadGameProgress(CardPool& cardpool, double& prob_comp, Player p[], int& turn)
{
	ifstream progress;
	progress.open("Progress.txt");
	string s;
	getline(progress, s);
	cardpool.Load(s);
	getline(progress, s);
	prob_comp= stoi(s);
	getline(progress,p[0].playername);
	getline(progress,s);
	p[0].cardset.Load(s);
	getline(progress,p[1].playername);
	getline(progress,s);
	p[1].cardset.Load(s);
	getline(progress, s);
	turn= stoi(s);
}

bool GameOver(Player p[], CardPool cardpool) {
	if (p[0].cardset.NoHidden() || p[1].cardset.NoHidden() || cardpool.Empty())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void OutputGameProgress(CardPool& cardpool, double& probcomp, Player p[], int& turn)
{
	ofstream progress;
	progress.open("Progress.txt");
	progress << cardpool.Archive() << endl;
	progress << probcomp << endl;
	progress << p[0].playername << endl;
	progress << p[0].cardset.Archive() << endl;
	progress << p[1].playername << endl;
	progress << p[1].cardset.Archive() << endl;
	progress << turn << endl;
	progress.close();
}

void GamePlay(CardPool& cardpool, double& prob_comp, Player p[], int& turn) {
	string newcard;
	bool guesschance = 1;
	newcard = cardpool.Pick();
	string guesscard;
	int guessposition;
	if (turn % 2 == 1) {
		cout << "You get this card from the cardpool: ";
		cout << newcard << endl;
		while (guesschance)
		{
			cout << "PLease have a guess." << endl;
			cout << "You want to guess which card? (The leftmost position is 0.)" << endl;
			cout << "Please enter the position:" << endl;
			cin >> guessposition;
			cout << "You guess the card at that position should be:" << endl;
			cin >> guesscard;
			if (p[1].cardset.Judge(guessposition, guesscard))
			{
				p[1].cardset.TurnOver(guessposition);
				cout << setw(8) << p[0].playername << ": " << p[0].cardset.Display() << endl;
				cout << setw(8) << p[0].playername << ": " << p[0].cardset.SecretDisplay() << endl;
				cout << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;
				cout << "Continue another guess or not? (Y/N)" << endl;
				string command;
				cin >> command;
				while (command != "Y" && command != "N")
				{
					cout << "Please input \"Y\" or \"N\"." << endl;
					cin >> command;
				}
				if (command == "N")
				{
					p[0].cardset.Append(newcard, 1);
					guesschance = 0;
				}			
			}
			else
			{
				p[0].cardset.Append(newcard, 0);
				guesschance = 0;
				cout << setw(8) << p[0].playername << ": " << p[0].cardset.Display() << endl;
				cout << setw(8) << p[0].playername << ": " << p[0].cardset.SecretDisplay() << endl;
				cout << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;
			}
		}
	}
	else
	{
		cout << "Computer gets one card from the cardpool." << endl;
		srand((unsigned int)(time(0)));
		if ((rand() % 10 + 1) <= (prob_comp * 10))
		{
			p[0].cardset.ForcedTurnOver();
			p[1].cardset.Append(newcard, 1);
			cout << setw(8) << p[0].playername << ": " << p[0].cardset.Display() << endl;
			cout << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;
		}
		else
		{
			p[1].cardset.Append(newcard, 0);
			cout << setw(8) << p[0].playername << ": " << p[0].cardset.Display() << endl;
			cout << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;
		}
	}
	turn += 1;
}

void OutputSummary(Player p[], CardPool cardpool, int turn)
{
	ofstream summary;
	summary.open("Summary.txt");
	summary << "Total turns: " << turn << endl;
	summary << setw(8) << p[0].playername << ": " << p[0].cardset.Display() << endl;
	summary << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;
	summary << setw(8)  << "Cardpool" << ": " << cardpool.Display() << endl;
	if (cardpool.Empty())
	{
		if (p[0].cardset.HiddenNum() > p[1].cardset.HiddenNum())
		{
			summary << "Winner: " << p[0].playername << endl;
		}
		else if (p[0].cardset.HiddenNum() < p[1].cardset.HiddenNum())
		{
			summary << "Winner: " << p[1].playername << endl;
		}
		else
		{
			summary << "End in a draw." << endl;
		}
	}
	else
	{
		summary << "Winner: ";
		if (p[0].cardset.NoHidden())
		{
			summary << p[1].playername << endl;
		}
		else if ((p[1].cardset.NoHidden()))
		{
			summary << p[0].playername << endl;
		}
	}
}
