//
// Created by piraka9011 on 1/28/17.
//

#ifndef PROJ1A_RESPONSE_H
#define PROJ1A_RESPONSE_H

#include <iostream>
#include <ostream>
#include "../include/code.h"

class response {

private:
    int correct;
    int incorrect;
    std::vector<int> secretCode;
    std::vector<int> guessCode;

public:

    // Default constructor
    response();

    // Setters and getters for check in/correct
    void setCorrect(code guessCode)
        { correct = inputCode.checkCorrect(guessCode);};
    int getCorrect() const { return correct;};

    void setIncorrect(code guessCode)
        { incorrect = guessCode.checkInorrect(guessCode);};
    int getIncorrect() const { return incorrect;}

    void setGuessCode(code guessCode){ guessCode.getGuessCode();}
    void setSecretCode(code secretCode) { secretCode.getSecretCode();}

    /// May need to add & operator to param if logic errors pop up
    friend std::ostream& operator <<(const response resp);
    bool operator ==(const response respL, const response respR);



};


#endif //PROJ1A_RESPONSE_H
