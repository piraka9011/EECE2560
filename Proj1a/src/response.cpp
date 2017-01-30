//
// Created by piraka9011 on 1/28/17.
//

#include "../include/response.h"

response::response()
{

}


bool response::operator ==(const response respL, const response respR)
{
    for (int i = 0; i < respL.secretCode.size(); i++)
    {
        if (respL.secretCode.at(i) != respR.guessCode.at(i))
            return false;
        else
            return true;
    }
}

friend std::ostream& response::operator<<(std::ostream& os, const response resp)
{
    os << "Correct digits in correct position: "
       << resp.getCorrect() << '\n';
    os << "Correct digits in incorrect position: "
       << resp.getIncorrect() << '\n';
    return os;
}

