#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "CardSet.h"
#include "CardPool.h"
using namespace std;

struct Player
{
	string playername;
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
void output_game_progress(CardPool &cardpool,double &prob_comp,Player p[],int &turn);
//output the progress into Progress.txt when the game is paused
void output_summary(Player p[]);
//output the summary results of each player in the game.

int main()
{
	string command;
	double prob_comp=0;
	CardPool cardpool;   
	Player p[2];
	int turn=1;
	p[1].playername="Computer"；
	new_or_continue(command,cardpool,prob_comp,p,turn);
	cout << p[0].playername << " " << p[0].cardset.Display()<<endl;
	cout << p[0].playername << " " << p[0].cardset.Display_mycard()<<endl;
	cout << p[1].playername << " " << p[1].cardset.Display()<<endl;
	while(command != "pause" & gameover(p)==0)
	{
		gameplay(command,cardpool,prob_comp,p,turn);
	}
	if (command == "pause")
	{
		output_game_progress(cardpool,prob_comp,p,turn);
	}
	else if (gameover(p)==1)
	{
		output_summary(p);
	}
}


void SetDifficulty(double &prob_comp)
{
	string difficulty_level;
	cout << "Please choose the difficulty level.(EASY/NORMAL/HARD/EXPERT/HELL)"<<endl;
	cin >> difficulty_level;
	while (prob_comp = 0)
	{
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
		else
		{
			cout << "Please input \"EASY\"/\"NORMAL\"/\"HARD\"/\"EXPERT\"/\"HELL\"! "<<endl;
		}
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
		cin >> p[0].playername;
	}
	else if (command=="n")
		load_game_process(cardpool,prob_comp,p,turn);
}

void load_game_process(CardPool &cardpool,double &prob_comp,Player p[],int &turn)
{
	ifstream progress;
	progress.open("Progress.txt");
	string s;
	getline(progress,s);
	cardpool.Input(s);
	progress >> prob_comp;
	progress >> p[0].playername;
	getline(progress,s);
	p[0].cardset.Input(s);
	progress >> p[1].playername;
	getline(progress,s);
	p[1].cardset.Input(s);
	progress >> turn;
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

void output_game_progress(CardPool &cardpool,double &prob_comp,Player p[],int &turn)
{
	ofstream progress;
	progress.open("Progress.txt");
	progress<<cardpool.Archive()<<endl;
	progress<<prob_comp<<endl;
	progress<<p[0].playername<<endl;
	progress<<p[0].cardset.Archive()<<endl;
	progress<<p[1].playername<<endl;
	progress<<p[1].cardset.Archive()<<endl;
	progress<<turn<<endl;
	progress.close();
}

void gameplay(string &command,CardPool &cardpool,double &prob_comp,Player p[],int &turn){
	string newcard,choice="Continue";
	newcard = cardpool.Pick();
	int position;
	if (turn%2==1){
		cout << newcard <<endl;
		p[0].cardset.Append(newcard);
		while (choice=="Continue")
		{
			cout << "PLease have a guess." <<endl;
			cin >> command;
			position=p[1].cardset.Find(command)
			if (position!=-1)
			{
				p[1].cardset.TurnOver(position);
				cout << p[0].playername << " " << p[0].cardset.Display()<<endl;
				cout << p[0].playername << " " << p[0].cardset.Display_mycard()<<endl;
				cout << p[1].playername << " " << p[1].cardset.Display()<<endl;
				cout <<"Continue guess nor not?(Continue/Stop)"<<endl;
				cin >> command;
				choice = command;
			}
			else
			{
				position = p[0].cardset.Find(newcard);
				p[0].cardset.TurnOver(position);
				cout << p[0].playername << " " << p[0].cardset.Display()<<endl;
				cout << p[0].playername << " " << p[0].cardset.Display_mycard()<<endl;
				cout << p[1].playername << " " << p[1].cardset.Display()<<endl;
				choice = "Stop";
			}
		}
	}
	else
	{
	}
	turn += 1;
}
