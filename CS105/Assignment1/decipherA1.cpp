#include <iostream>
#include <cctype>
#include <string>

//YOUR NAME HERE

using namespace std;

char max_frequency (const char str[]);
void rotate (char str[], int rotDist);

int main() {
	//Your CODE HERE
	/* Read in file using cin, 
	   get max frequence character (aka decipher) via the max_frequence function,
	   translate text via the rotate function,
	   and then print out fixed text! */

	return 0;
}

/*This function takes a character array, and finds
the alphabetic character that occurs the most frequently and returns it
*/
char max_frequency (const char str[]) {
	/*can use functions such as isalpha(myChar) 
	  and tolower(myChar) or toupper(myChar) 
	  and islower(myChar) or isupper(myChar) */
	return str[0];
}

/*This function takes a character array and a rotation distance,
and changes each alphabetical character in the array by the rotation distance 
*/
void rotate (char str[], int rotDist) {

}