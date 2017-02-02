/**/

#ifndef PROJ1A_MASTERMIND_H
#define PROJ1A_MASTERMIND_H

#include "code.h"
#include "response.h"

class mastermind
{

private:
    int length, range;   // Length & Range
    code masterCode;

public:
    // Default constructor
    mastermind() : masterCode(5, 10) { length = 5; range = 10;};

    // Constructor with user params
    mastermind(int n, int m) : masterCode(n, m) { length = n; range = m;};

    // Read from user guess
    code humanGuess();

    // Return user response
    response getResponse(code guessCode, code secretCode);

    // Checks if game is won
    bool isSolved(response respL, response respR);

    // Main function that inits random code and prints game console
    void playGame();

    // Prints secret code
    void printSecretCode(){for (auto i: masterCode.getSecretCode())std::cout << i << " ";};

};


#endif //PROJ1A_MASTERMIND_H