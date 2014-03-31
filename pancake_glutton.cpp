// Pancake Glutton: the least, the most, and sort
// A simple program that asks the user to enter the number of pancakes eaten for breakfast by 10 different people (Person 1, Person 2, ..., Person 10)
// Once the data has been entered the program must analyze the data and output which person ate the least and the most pancakes for breakfast.
// Then it also outputs a list in order of number of pancakes eaten of all 10 people.

#include <iostream>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

int pancakes [10] = {};
int pancakes_sorted [2][10] = {};


// returns the index of the person who eats the most pancakes.
// modifies param amount (passed in by reference) to be the amount this person ate.
int theMost(int& amount) {
	int res = -1;
	amount = INT_MIN;
	for (int i = 0; i < 10; i++) {
		if (pancakes[i] > amount) {
			amount = pancakes[i];
			res = i;
		}
	}
	return res;
}

// returns the index of the person who eats the least pancakes.
// modifies param amount (passed in by reference) to be the amount this person ate.
int theLeast(int& amount) {
	int res = -1;
	amount = INT_MAX;
	for (int i = 0; i < 10; i++) {
		if (pancakes[i] < amount) {
			amount = pancakes[i];
			res = i;
		}
	}
	return res;
}

// simple sort, but order N^2
// at the end of the sort, pancakes array will lose its original data and have -1 values
void sortPancakes() {
	for (int i = 0; i < 10; i++) {
		int amount = -1;
		int the_most = theMost(amount);
		pancakes_sorted[i][0] = the_most;
		pancakes_sorted[i][1] = amount;
		
		// this is to mark this person that we already considered them
		pancakes[the_most] = -1;
	}
}

int main() {
	
	string input;
	for (int i = 0; i < 10; i++) {
		cout << "Enter non-negative number of pancakes eaten by person " << i << ": ";
		getline(cin, input);
		stringstream(input) >> pancakes[i];
	}
	int amount = 0;
	
	// person who ate the most
	cout << "The person who ate the MOST pancakes is: " << theMost(amount) << endl;
	
	// person who ate the least
	cout << "The person who ate the LEAST pancakes is: " << theLeast(amount) << endl;
	
	// Sorted list of people who eat the most first
	sortPancakes();
	cout << "Sorted list of people who eat the most pancakes first: " << endl;
	for(int i = 0; i < 10; i++) {
		cout << "Person " << pancakes_sorted[i][0] << ": ate " << pancakes_sorted[i][1] << " pancakes" << endl;
	}
	
	return 0;
}