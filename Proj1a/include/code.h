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

public:
    // Constructor
    code(int n, int m);
    // Inits code randomly
    void randomInit();
    // returns the number of correct digits in the correct location
    int checkCorrect(code codeGuess);
    // returns the number of correct digits in the incorrect location
    int checkIncorrect(code codeGuess);
    void setCode(std::vector<int> userCode){userGuess = userCode;};
    std::vector<int> getCode(){return userGuess;};
};


#endif //CODE_H
