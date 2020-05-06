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

void new_or_continue(string &command,CardPool &cardpool,double &prob_comp,Player p[],int &turn);
//choose to start a new game or continue the last game and finish the settings
void SetDifficulty(double &prob_comp);
//choose the game difficulty
void load_game_process(CardPool &cardpool,double &prob_comp,Player p[],int &turn);
//input the progress of the last game
void gameplay(string &command,CardPool &cardpool,double &prob_comp,Player p[],int &turn);
//gameplaying
bool gameover(Player p[]);
//Judge whether one of the player's card are all turned over

int main()
{
	string command;
	double prob_comp;
	CardPool cardpool;   
	Player p[2];
	int turn=1;
	p[1].palyername="Computer"；
	new_or_continue(command,cardpool,prob_comp,p,turn);
	while(command != "pause" & gameover(p)==0)
	{
		gameplay(command,cardpool,prob_comp,p,turn);
	}
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

void new_or_continue(string &command,CardPool &cardpool,double &prob_comp,Player p[],int &turn)
{
	cout<< "Start a new game?(y/n)"<<endl;
	cin >> command;
	while (command != "y" || command != "n")
	{
		cout<< "Please input \"y\"/\"n\"! "<<endl;
		cin >> command;
	}
	if (command=="y")
	{
		SetDifficulty(prob_comp);
		cardpool.Initialize();
		p[0].cardset.Initialize();
		p[1].cardset.Initialize();
		for (int i=0;i<4;i++)
			p[0].cardset.Append(cardpool.Pick());
		for (int i=0;i<4;i++)
			p[1].cardset.Append(cardpool.Pick());
		cout << "Please input your name."<<endl;
		cin >> p[0].palyername;
	}
	else if (command=="n")
		load_game_process(cardpool,prob_comp,p,turn);
}

void load_game_process(CardPool &cardpool,double &prob_comp,Player p[],int &turn)
void gameplay(string &command,CardPool &cardpool,double &prob_comp,Player p[],int &turn){

}

bool gameover(Player p[]){
	if (p[0].cardset.Judge_game_over()=1 || p[1].cardset.Judge_game_over()=1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
