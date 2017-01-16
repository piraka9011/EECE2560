//
// Created by piraka9011 on 1/15/17.
//

#include "../include/code.h"

code::code(int n, int m){
    this->n = n;
    this->m = m;
}

// Inits code randomly
void code::randomInit(){
    for (int i = 0; i < n; i++)
        secretCode.push_back(rand() % m);
}

int code::checkCorrect(std::vector<int> codeGuess) {
    int correctPos = 0;
    for (int i = 0; i < codeGuess.size(); i++) {
        if (secretCode.at(i) == codeGuess.at(i))
            correctPos++;
    }
    return correctPos;
}

int code::checkIncorrect(std::vector<int> codeGuess) {
    for (int i = 0; i < codeGuess.size(); i++) {

    }
}