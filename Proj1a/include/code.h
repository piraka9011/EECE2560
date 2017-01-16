//
// Created by piraka9011 on 1/15/17.
//

#ifndef CODE_H
#define CODE_H

#include <vector>
#include <cstdlib>

class code {

private:
    int n;
    int m;
    std::vector<int> secretCode;

public:
    // Constructor
    code(int n, int m);
    // Inits code randomly
    void randomInit();
    // returns the number of correct digits in the correct location
    int checkCorrect(std::vector<int> codeGuess);

    // returns the number of correct digits in the incorrect location
    int checkIncorrect(std::vector<int> codeGuess);
};


#endif //CODE_H
