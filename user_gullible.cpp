// While( user == gullible )
// Program #1: a simple program that continues to asks the user to enter any number other than 5 until the user enters the number 5.
// Then tell the user "Hey! you weren't supposed to enter 5!" and exit the program.
// After 10 iterations if the user still hasn't entered 5 will tell the user "Wow, you're more patient then I am, you win." and exit.
// Program #2: a program that asks the user to enter any number other than the number equal to the number of times they've been asked 
// to enter a number. (i.e on the first iteration "Please enter any number other than 0" and on the second iteration "Please enter any
// number other than 1"m etc. etc. The program must behave accordingly exiting when the user enters the number they were asked not to.)


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int program1() {
	string user_response;
	int user_input;
	int count = 10;
	
	while (user_input != 5 && count > 0){		
		cout << "Enter a number that is not 5: ";
		getline(cin, user_response);
		stringstream(user_response) >> user_input;
		
		count--;
	} // keep asking user to input unless they entered 5 or it's more than 10 times
	
	if (count == 0) 
		cout << "Wow, you're more patient then I am, you win" << endl;
	else
		cout << "Hey! you weren't supposed to enter 5!" << endl;
	return 0;
}

int program2() {
	string user_response;
	int user_input;
	int round = -1;
	
	do {
		round++;
		cout << "Enter a number that is not " << round << ": ";
		getline(cin, user_response);
		stringstream(user_response) >> user_input;
	} while (user_input != round);
	
	cout << "Hey! you weren't supposed to enter " << round << "!" << endl;
	
	return 0;
}

int main() {
	string program;
	
	cout << "Enter 1 or 2 to run a program: ";
	getline(cin, program);
	
	if(program == "1")
		return program1();
	else
		return program2();
}