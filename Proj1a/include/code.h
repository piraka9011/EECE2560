/**
	EECE2560: Proj1a
	code.h
	Purpose: This header file defines the private & public data members and functions
    that will be part of the Code class
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 1/26/17

*/

#ifndef CODE_H
#define CODE_H

#include <algorithm>    // std::reverse
#include <cstdlib>      // rand() & srand()
#include <ctime>        // time()
#include <functional>   // std::not_equal_to
#include <iostream>
#include <numeric>      // std::iota
#include <vector>

class code
{

private:
    int n;  // Length
    int m;  // Range
    std::vector<int> secretCode; // Vector to store secret code
    std::vector<int> userGuess;  // Vector to store guess code
    std::vector<bool> rightDig;  // Used to check if digit has been checked

public:
    // Constructor
    code(int n, int m);

    // Inits code randomly
    void randomInit();

    // Returns the number of correct digits in the correct location
    int checkCorrect(code guessCode);

    // Returns the number of correct digits in the incorrect location
    int checkIncorrect(code guessCode);

    // Check if user won or not
    bool checkWin(int correctGuess);

    // Sets a code to member guess code
    void setGuessCode(std::vector<int> userCode){userGuess = userCode;};

    // Returns a guess code
    std::vector<int> getGuessCode(){return userGuess;};

    // Prints whether user won or not
    void printResult(bool result);

    // Gets for the correct/incorrect numbers
    int getCorrect(code guessCode){return checkCorrect(guessCode);}
    int getIncorrect(code guessCode){return checkIncorrect(guessCode);}

    /// DEBUGGING ONLY
    // Returns secret code as vector
    std::vector<int> getSecretCode(){return secretCode;};

};

#endif //CODE_H
