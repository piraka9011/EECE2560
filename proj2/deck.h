//
// Created by river on 2/2/17.
//

#ifndef FLIP_DECK_H
#define FLIP_DECK_H

#include "card.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <random>

class Deck {

private:
    const int DECK_SIZE = 52;
    const int NUM_SUIT = 4;
    const int NUM_VALUE = 13;

public:
    Deck();
    void shuffle();

    friend std::ostream& operator << (std::ostream& os, const node<Card> &n);
};


#endif //FLIP_DECK_H
