//
// Created by piraka9011 on 1/15/17.
//

#include "../include/code.h"

code::code(int n, int m){
    this->n = n;
    this->m = m;
}

// Inits secret code randomly
void code::randomInit(){
    for (int i = 0; i < n; i++)
        secretCode.push_back(rand() % m);
}

// Check if guess is in correct position
int code::checkCorrect(code codeGuess) {
    int correctPos = 0; // Count for correct guesses
    // Loop through secret code and check if guess matches
    for (int i = 0; i < codeGuess.getCode().size(); i++) {
        if (secretCode.at(i) == codeGuess.getCode().at(i))
            correctPos++;
    }
    // Return the number of guesses
    return correctPos;
}

int code::checkIncorrect(code codeGuess) {
    std::vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> rightDig;
    for (auto incorrectPos : digits) {
        if (std::binary_search(secretCode.begin(), secretCode.end(), digits))
            rightDig.push_back(incorrectPos);
    }
}