//
// Created by river on 2/2/17.
//

#include "card.h"

Card::Card()
{
    value = 0;
    suit = 0;
}

Card::Card(int value, int suit)
{
    this -> value = value;
    this -> suit = suit;
}

std::ostream& operator << (std::ostream os, const Card& c)
{
    switch (c.value) {
        case 0:
            os << "Value: Ace\n";
        case 11:
            os << "Value: Joker\n";
        case 12:
            os << "Value: Queen\n";
        case 13:
            os << "Value: King\n";
        default:
            os << "Value: " << c.value << '\n';
    }
    switch (c.suit)
    {
        case 0:
            os << "Suite: Club\n";
        case 1:
            os << "Suite: Diamond\n";
        case 2:
            os << "Suite: Heart\n";
        case 3:
            os << "Suite: Spade\n";
        default:
            os << "Error, no suite found!\n";
    }
    return os;
}