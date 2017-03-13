#include "readint.h"
#include <stdexcept>
#include <iostream>
#include <limits>
#include <ios>
using namespace std;

///////////////////////
// Ben Morledge-Hampton
// 
// Exception Handling and Unit-Testing
//
// 3/8/2017
///////////////////////

/**
Function to return an integer as it is input by the user.
However, the program will only return the integer if it
falls within the given bounds.  If a non-number is entered,
the function will discard the invalid input, and reprompt for input.
If a number outside of the range is given, the function will ask again
until valid input is obtained.  If the given range is empty, an 
invalid_argument exception will be thrown.
@param prompt The message displayed to the user to prompt input.
@param low The first integer on the lower bound which will be considered invalid.
@param high The first integer on the upper bound which will be considered invalid.
@Return the user's valid input.
*/
int read_int(const string &prompt, int low, int high) {

	// Throw an invalid_argument exception if the given range is empty.
	if (high - low < 1) throw invalid_argument("Range is empty");

	cin.exceptions(ios_base::failbit);
	int num = 0;
	while (true) { // Loop until valid input is received.

		try {
			// Read in the user's input.
			cout << prompt;
			cin >> num;
			// Check to see if the response falls within the bounds.
			// If it does, return it.
			if (num > low && num < high) return num;
			// If it doesn't, reprompt for input.
			else cout << "That is not within the given bounds.\n";
		}
		catch (ios_base::failure& ex) {
			cout << "Bad numeric string -- try again\n";
			// Reset the error flag
			cin.clear();
			// Skip current input line
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}

}