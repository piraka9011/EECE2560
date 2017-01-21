//
// Created by piraka9011 on 1/15/17.
//

#ifndef CODE_H
#define CODE_H

#include <algorithm>
#include <vector>
#include <cstdlib>

class code {

private:
    int n;
    int m;
    std::vector<int> secretCode;
    std::vector<int> userGuess;
    std::vector<bool> rightDig;

public:
    // Constructor
    code(int n, int m);
    // Inits code randomly
    void randomInit();
    // returns the number of correct digits in the correct location
    int checkCorrect(code guessCode);
    // returns the number of correct digits in the incorrect location
    int checkIncorrect(code guessCode);
    // Sets a code to member guess code
    void setGuessCode(std::vector<int> userCode){userGuess = userCode;};
    // Returns a guess code
    std::vector<int> getGuessCode(){return userGuess;};
};


#endif //CODE_H
