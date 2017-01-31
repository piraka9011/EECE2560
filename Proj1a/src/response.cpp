//
// Created by piraka9011 on 1/28/17.
//

#include "../include/response.h"

response::response()
{

}


bool response::operator ==(const response &respR)
{
        if (secretCode == respR.guessCode)
            return true;
        else if (respR.secretCode == guessCode)
            return true;
        else
            return false;
}

std::ostream& operator<< (std::ostream& os, const response resp)
{
    os << "Correct digits in correct position: "
       << resp.getCorrect() << '\n';
    os << "Correct digits in incorrect position: "
       << resp.getIncorrect() << '\n';
    return os;
}

std::istream& operator>> (std::istream& is, response& resp)
{
    is >> resp.correct >> resp.incorrect;
    return is;
}

