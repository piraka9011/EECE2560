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
    // Add random numbers to secret code in range [0, m-1]
    for (int i = 0; i < n; i++)
        secretCode.push_back(rand() % (m-1));
    // Set the size to determine the
    rightDig.resize(n, false);
}

// Check if guess is in correct position
int code::checkCorrect(code guessCode) {
    int correctPos = 0; // Count for correct guesses
    // Loop through secret code and check if guess matches
    for (int i = 0; i < n; i++) {
        if (secretCode.at(i) == guessCode.getGuessCode().at(i)) {
            correctPos++;
            rightDig.at(i) = true;
        }
    }
    // Return the number of guesses
    return correctPos;
}

int code::checkIncorrect(code guessCode) {
    // Make new vector to store possible digits
    std::vector<int> digits(m-1);
    // Fill digits vector with numbers from 0 to m-1
    std::iota(digits.begin(), digits.end(), 0);
    // Variable to count the number of digits in the code but in the incorrect position
    int incorrectPos = 0;

    // Loop through all numbers in the code
    for (int i = 0; i < n; i++){
        // Loop through all possible digits
        for (int j = 0; j < digits.size(); j++){
            // If the digit is in the guess code, increment count of incorrect position
            if (guessCode.getGuessCode().at(i) == digits.at(j)){
                // However, check if the digit is already counted
                if (!rightDig.at(i))
                    incorrectPos++;
            }
        }
    }
}