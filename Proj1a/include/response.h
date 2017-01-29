//
// Created by piraka9011 on 1/28/17.
//

#ifndef PROJ1A_RESPONSE_H
#define PROJ1A_RESPONSE_H


class response {

private:
    int correct;
    int incorrect;

public:

    // Default constructor
    response();

    // Setters and getters for check in/correct
    void setCorrect();
    int getCorrect(){ return correct;};
    int getIncorrect(){ return incorrect;};

    /// May need to add & operator to param if logic errors pop up
    response operator <<(const response);
    bool operator ==(const response);



};


#endif //PROJ1A_RESPONSE_H
