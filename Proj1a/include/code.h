//
// Created by piraka9011 on 1/15/17.
//

#ifndef CODE_H
#define CODE_H

#include <algorithm>    // std::reverse
#include <cstdlib>      // rand()
#include <functional>   // std::not_equal_to
#include <iostream>
#include <numeric>      // std::iota
#include <vector>
#include <ctime>


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

    // Check if user won or not
    bool checkWin(int correctGuess);

    // Sets a code to member guess code
    void setGuessCode(std::vector<int> userCode){userGuess = userCode;};

    // Returns a guess code
    std::vector<int> getGuessCode(){return userGuess;};

    // Prints whether user won or not
    void printResult(bool result);

    // Prints secret code
    void printSecretCode(){for (auto i: secretCode)std::cout << i << ' ';};

    /// DEBUGGING ONLY
    // Returns secretCode
    std::vector<int> getSecretCode(){return secretCode;};
};


#endif //CODE_H
