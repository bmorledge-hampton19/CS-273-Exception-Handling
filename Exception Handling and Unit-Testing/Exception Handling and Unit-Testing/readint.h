#ifndef READINT_H_
#define READINT_H_
#include <string>

/**
 Function to return an integer as it is input by the user.
 However, the program will only return the integer if it
 falls within the given bounds.  If a non-number is entered,
 the function will discard the invalid input, and reprompt for input.
 @param prompt The message displayed to the user to prompt input.
 @param low The first integer on the lower bound which will be considered invalid.
 @param high The first integer on the upper bound which will be considered invalid.
 @Return the user's valid input.
*/
int read_int(const std::string &prompt, int low, int high);

#endif