#include <iostream>
#include <string>
using namespace std;



void set_up_new(string & difficulty,int & posibility){
	cout<< "Please choose the difficulty level.(easy/normal/hard/expert)"<<endl;
}




int main(){
	cout<< "Start a new game?(y/n)"<<endl;
	string command,mode,difficulty;
	int posibility;
	cin >> command;
	if (command=="y"){
		set_up_new();
	}

}
