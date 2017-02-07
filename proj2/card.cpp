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

std::ostream& operator << (std::ostream& os, const Card& c)
{
    switch (c.getValue()) {
        case 0:
            os << "Value: Ace\n";
        case 11:
            os << "Value: Joker\n";
        case 12:
            os << "Value: Queen\n";
        case 13:
            os << "Value: King\n";
        default:
            os << "Value: " << c.getValue()<< '\n';
    }
    switch (c.getSuit())
    {
        case 0:
            os << "Suit: Club\n";
        case 1:
            os << "Suit: Diamond\n";
        case 2:
            os << "Suit: Heart\n";
        case 3:
            os << "Suit: Spade\n";
    }
    return os;
}

/*
 *
 *
 *     default:
            os << "Error, no suite found!\n";
 *
 */