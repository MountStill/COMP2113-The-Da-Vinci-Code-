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
			cout << "Pleas input \"easy/normal/hard/expert\"! "<<endl;
	}
}




int main(){
	cout<< "Start a new game?(y/n)"<<endl;
	string command,mode,difficulty;
	int posibility=0;
	cin >> command;
	if (command=="y"){
		set_up_new();
	}

}
