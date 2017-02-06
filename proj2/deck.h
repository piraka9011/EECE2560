//
// Created by river on 2/2/17.
//

#ifndef FLIP_DECK_H
#define FLIP_DECK_H

#include "card.h"
#include "d_node.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <random>

class Deck {

private:
    const int DECK_SIZE = 52;
    const int NUM_SUIT = 4;
    const int NUM_VALUE = 13;
    node<Card> *headNode = new node<Card>;

public:
    Deck();
    void shuffle();
    int getDeckSize() const { return DECK_SIZE; };
    friend std::ostream& operator << (std::ostream& os, Deck &d);
};


#endif //FLIP_DECK_H
