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

public:

    // Default constructor
    response();

    // Setters and getters for check in/correct
    void setCorrect(code guessCode)
        { correct = guessCode.getCorrect(guessCode);};
    void setIncorrect(code guessCode)
        { incorrect = guessCode.getInorrect(guessCode);};
    int getCorrect() const { return correct;};
    int getIncorrect() const { return incorrect;};

    /// May need to add & operator to param if logic errors pop up
    friend std::ostream& operator <<(const response resp);
    bool operator ==(const response resp);



};


#endif //PROJ1A_RESPONSE_H
