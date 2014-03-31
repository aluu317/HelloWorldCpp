// grading program
// a very simple program that allows the user to enter the grade scored in a programming class (0-100).
// If the user scored a 100 then notify the user that they got a perfect score.
// it will notify the user of their letter grade
// 0-59 F 60-69 D 70-79 C 80-89 B 90-100 A
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string user_response;
	float user_grade = 101;
    
    // check to make sure the input is in range 0-100
    while (user_grade > 100 || user_grade < 0) {
    	cout << "Enter your grade (0-100): ";
    	getline(cin, user_response); // record user's grade
    	stringstream(user_response) >> user_grade; // store user's grade
    }
    
    string result = "You got ";
    if (user_grade >= 90) {
    	result += "an A.";
    	if (user_grade == 100)
    		result += " That is a perfect score!!!";
    } else if (user_grade >= 80) {
    	result += "a B.";
    } else if (user_grade >= 70) {
    	result += "a C.";
    } else if (user_grade >= 60) {
    	result += "a D.";
    } else {
    	result += "an F.";
    }
    
    cout << result << endl;
    
    return 0;
}