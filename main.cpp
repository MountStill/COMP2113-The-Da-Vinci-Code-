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

void Introduction();
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
	Introduction();
	CardPool cardpool;
	Player p[2];
	double probcomp = 0;
	int turn = 1;
	string command;
	p[1].playername = "Computer";
	NewOrLoadGame(cardpool, probcomp, p, turn);
	while (1)
	{
		cout << endl << "------------------------------" << endl;
		cout << endl << "This is turn " << turn << "." << endl;
		cout << endl << "The third view of two players' cardsets:" << endl;
		cout << "(\"XX\" means the number is hidden. \"B\" and \"W\" stand for the color.)" << endl << endl;
		cout << setw(8) << p[0].playername << ": " << p[0].cardset.Display() << endl;
		cout << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;
		cout << endl << "And you can see the details of your own cardset:" << endl << endl;
		cout << setw(8) << p[0].playername << ": " << p[0].cardset.SecretDisplay() << endl;
		cout << endl << "Continue the game? (Y/N)" << endl;
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
			cout << endl << "Your progress of this game is output." << endl;
			cout << endl << "You can load the progress next time to continue at where you stop." << endl;
			break;
		}
	}
}

void Introduction()
{
	ifstream introduction;
	introduction.open("Introduction.txt");
	string line;
	while (getline(introduction, line))
	{
		cout << line << endl;
	}
	introduction.close();
}

void SetDifficulty(double& probcomp)
{
	string difficultylevel;
	cout << endl << "Please choose the difficulty level. (EASY/NORMAL/HARD/EXPERT/HELL)" << endl;
	cin >> difficultylevel;
	while (difficultylevel != "EASY" && difficultylevel != "NORMAL" && difficultylevel != "HARD" \
	&& difficultylevel != "EXPERT" && difficultylevel != "HELL")
	{
		cout << "Please input \"EASY\"/\"NORMAL\"/\"HARD\"/\"EXPERT\"/\"HELL\"! " << endl;
	}
	if (difficultylevel == "EASY")
	{
		probcomp = 0.1;
	}
	else if (difficultylevel == "NORMAL")
	{
		probcomp = 0.3;
	}
	else if (difficultylevel == "HARD")
	{
		probcomp = 0.5;
	}
	else if (difficultylevel == "EXPERT")
	{
		probcomp = 0.8;
	}
	else if (difficultylevel == "HELL")
	{
		probcomp = 1.0;
	}
}

void NewOrLoadGame(CardPool& cardpool, double& prob_comp, Player p[], int& turn)
{
	string command;
	cout << "Start a new game? (Y/N) Please input \"Y\" if you do not have an progress archive." << endl;
	cin >> command;
	while (command != "Y" && command != "N")
	{
		cout << "Please input \"Y\" or \"N\"! " << endl;
		cin >> command;
	}
	if (command == "Y")
	{
		cout << endl << "New game starts." << endl;
		cout << endl << "Please enter your name. (No more than 8 characters.)" << endl;
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
		cout << endl << "Last game is loaded." << endl;
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
	prob_comp = stoi(s);
	getline(progress, p[0].playername);
	getline(progress, s);
	p[0].cardset.Load(s);
	getline(progress, p[1].playername);
	getline(progress, s);
	p[1].cardset.Load(s);
	getline(progress, s);
	turn = stoi(s);
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
	string* guesscard = new string;
	int* guessposition = new int;
	if (turn % 2 == 1) {
		cout << endl << "You get this card from the cardpool: ";
		cout << newcard << endl;
		while (guesschance)
		{
			cout << endl << "Please take a guess." << endl;
			cout << endl << "You want to guess which card? (The leftmost position is 0.)" << endl;
			cout << "Please enter the position:" << endl;
			cin >> *guessposition;
			while (*guessposition >= p[1].cardset.Num())
			{
				cout << "Please input an appropriate number! (The leftmost position is 0.)" << endl;
				cin >> *guessposition;
			}
			cout << "You guess the card at that position should be: (In the form like \"01B\" or \"10W\")" << endl;
			cin >> *guesscard;
			if (p[1].cardset.Judge(*guessposition, *guesscard))
			{
				cout << endl << "Your guess is correct. The opponent card is turned over as reward." << endl;
				p[1].cardset.TurnOver(*guessposition);
				cout << endl << "Your view of your cardset and the opponent's cardset:" << endl << endl;
				cout << setw(8) << p[0].playername << ": " << p[0].cardset.SecretDisplay() << endl;
				cout << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;
				cout << endl << "Continue another guess or not? (Y/N)" << endl;
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
				delete guesscard;
				delete guessposition;
				cout << endl << "Your guess is wrong. Your card just drawn is turned over as punishment." << endl;
				p[0].cardset.Append(newcard, 0);
				guesschance = 0;
				cout << endl << "Your view of your cardset and the opponent's cardset:" << endl << endl;
				cout << setw(8) << p[0].playername << ": " << p[0].cardset.SecretDisplay() << endl;
				cout << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;
			}
		}
	}
	else
	{
		cout << endl << "Computer gets one card from the cardpool." << endl;
		srand((unsigned int)(time(0)));
		if ((rand() % 10 + 1) <= (prob_comp * 10))
		{
			cout << endl << "The computer's guess is correct." << endl;
			p[0].cardset.ForcedTurnOver();
			p[1].cardset.Append(newcard, 1);
			cout << endl << "The third view of two players' cardsets:" << endl << endl;
			cout << setw(8) << p[0].playername << ": " << p[0].cardset.Display() << endl;
			cout << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;
		}
		else
		{
			cout << endl << "The computer's guess is wrong." << endl;
			cout << endl << "The third view of two players' cardsets:" << endl << endl;
			p[1].cardset.Append(newcard, 0);
			cout << setw(8) << p[0].playername << ": " << p[0].cardset.Display() << endl;
			cout << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;
		}
	}
	turn += 1;
}

void OutputSummary(Player p[], CardPool cardpool, int turn)
{
	cout << endl << "The game is ended." << endl;
	ofstream summary;
	summary.open("Summary.txt");
	summary << "Total turns: " << turn << endl;
	summary << endl << "The third view of two players' cardsets:" << endl << endl;
	summary << setw(8) << p[0].playername << ": " << p[0].cardset.Display() << endl;
	summary << setw(8) << p[1].playername << ": " << p[1].cardset.Display() << endl;

	if (cardpool.Empty())
	{
		if (p[0].cardset.HiddenNum() > p[1].cardset.HiddenNum())
		{
			summary << endl << "No cards left in the cardpool." << endl;
			summary << endl << "Winner: " << p[0].playername << endl;
			cout << endl << "Winner: " << p[0].playername << endl;
		}
		else if (p[0].cardset.HiddenNum() < p[1].cardset.HiddenNum())
		{
			summary << endl << "Winner: " << p[1].playername << endl;
			cout << endl << "Winner: " << p[1].playername << endl;
		}
		else
		{
			summary << endl << "End in a draw." << endl;
			cout << endl << "End in a draw." << endl;
		}
	}
	else
	{
		summary << endl << "Remained cards in the cardpool:" << endl << endl;
		summary << setw(8) << "Cardpool" << ": " << cardpool.Display() << endl;
		summary << endl << "Winner: ";
		cout << endl << "Winner: ";
		if (p[0].cardset.NoHidden())
		{
			summary << p[1].playername << endl;
			cout << p[1].playername << endl;
		}
		else if ((p[1].cardset.NoHidden()))
		{
			summary << p[0].playername << endl;
			cout << p[0].playername << endl;
		}
	}
	cout << endl << "The summary of the game is output." << endl;
	cout << endl << "You can find more details in the output file." << endl;
	cout << endl << "Thanks for playing this game~" << endl;
}
