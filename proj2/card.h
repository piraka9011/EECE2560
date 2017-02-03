//
// Created by river on 2/2/17.
//

#ifndef CARD_H
#define CARD_H

//#include <ostream>
#include <iostream>

class Card {

private:
    int value; // 0-12 -> 2-JQKA
    int suit; // 0-4 -> Club/Diamond/Heart/Spade

public:
    Card();
    void setValue(int newVal) { value = newVal; }
    void setSuit(int newSuit) { suit = newSuit; }
    int getValue() { return value; }
    int getSuit() { return suit; }
    friend std::ostream& operator << (std::ostream os, const Card& c);

};

#endif //PROJ2_CARD_H
