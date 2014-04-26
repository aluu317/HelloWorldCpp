// Bracketing Search
// A program that calculates a random number 1 through 100. The program then asks the user to guess the number.
// If the user guesses too high or too low then the program should output "too high" or "too low" accordingly.
// The program must let the user continue to guess until the user correctly guesses the number.

// Modification 1: output how many guesses it took the user to correctly guess the right number.
// Modification 2: Modify the program so that instead of the user guessing a number the computer came up with, 
//                 the computer guesses the number that the user has secretely decided. 
//                 The user must tell the computer whether it guesed too high or too low.
//                 No matter what number the user thinks of (1-100) the computer can guess it in 7 or less guesses.


#include <iostream>      
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>

using namespace std;

void userGuesses() {
	string user_input;
	int iSecret, iGuess;
  	int iCount = 0;

	/* generate secret number between 1 and 100: */
	srand (time(NULL));
	iSecret = rand() % 100 + 1;

	do {
		cout << ("Guess the secret number (1 to 100): ");
		getline (cin, user_input);
		stringstream(user_input) >> iGuess;

		iCount++; // increment number of guesses user has used
		if (iSecret < iGuess) 
			cout << "The secret number is lower" << endl;
		else if (iSecret > iGuess) 
			cout << "The secret number is higher" << endl;
	} while (iSecret!=iGuess);

	cout << "Congratulations! You guessed the correct secret number in " << iCount << " guesses" << endl;
}

void computerGuesses() {
	string user_input;
	int range_start = 1;
	int range_end = 100;
	int iGuess;
  	int iCount = 0;

	cout << "Think of a secret number (1 to 100)." << endl;
	do {
		iGuess = (range_start + range_end) / 2;
		iCount++; // increment number of guesses
		cout << "The computer's guess number " << iCount << " is: " << iGuess << endl;
		cout << "Enter:\n0 for correct\n1 for this guess is too low!\n2 for this guess is too high! ";
		getline (cin, user_input);

		if (user_input == "1") {// guessed too low, go higher
			range_start = iGuess;
		}
		else if (user_input == "2") { // guessed too high, go lower 
			range_end = iGuess;
		}
	} while (user_input!= "0");
	
	cout << "Yay! The computer has guessed the correct secret number in " << iCount << " guesses" << endl;
}

int main ()
{
	string user_input;
	int program;
	
  	cout << "1 for user guesses what computer thinks, 2 for computer guesses what user thinks: ";
  	getline(cin, user_input);
  	stringstream(user_input) >> program;
  	
  	if (program == 1)
  		userGuesses();
  	else
  		computerGuesses();
	
	return 0;
}