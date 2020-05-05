#include <iostream>
#include <string>
using namespace std;



void set_up_new(string & difficulty,int & posibility){
	cout << "Please choose the difficulty level.(easy/normal/hard/expert)"<<endl;
	cin >> difficulty;
	while (posibility == 0){
		if (difficulty == "easy")
			posibility = 30;
		else if(difficulty == "normal")
			posibility = 50;
		else if(difficulty == "hard")
			posibility = 80;
		else if(difficulty == "expert")
			posibility = 95;
		else
			cout << "Please input \"easy/normal/hard/expert\"! "<<endl;
	}
}

void load_game_process(player &p1,player &p2,player &pool,int &turn){
}


int main(){
	cout<< "Start a new game?(y/n)"<<endl;
	string command,mode,difficulty;
	int posibility=0;
	player p1,p2,pool;
	int turn;
	cin >> command;
	if (command=="y"){
		set_up_new(difficulty,possibility);
	}
	else
		load_game_process(p1,p2,pool,turn);

}
