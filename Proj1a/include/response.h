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
    void setCorrect(code GC, code SC)
        { correct = SC.checkCorrect(GC);};
    int getCorrect() const { return correct;};

    void setIncorrect(code GC, code SC)
        { incorrect = SC.checkIncorrect(GC);};
    int getIncorrect() const { return incorrect;}

    void setGuessCode(code GC){ guessCode = GC.getGuessCode();}
    void setSecretCode(code SC) { secretCode = SC.getSecretCode();}

    /// May need to add & operator to param if logic errors pop up
    friend std::ostream& operator<< (std::ostream& os, const response resp);
    friend std::istream& operator>> (std::istream& is, response& resp);
    bool operator ==(const response &respR);



};


#endif //PROJ1A_RESPONSE_H