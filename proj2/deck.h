//
// Created by river on 2/2/17.
//

#ifndef FLIP_DECK_H
#define FLIP_DECK_H

#include "card.h"
#include "d_node.h"
#include "LinkedList.h"
#include <algorithm>
#include <list>
#include <random>
#include <ctime>

class Deck {

private:
    const int DECK_SIZE = 52;
    const int NUM_SUIT = 4;
    const int NUM_VALUE = 14;
    LinkedList deck;

public:
    Deck();
    void shuffle();
    void swap(node<Card> *a, node<Card> *b);
    int getDeckSize() const { return DECK_SIZE; };
    node<Card>* getHeadNode() {return deck.getHeadNode(); }
    friend std::ostream& operator << (std::ostream& os, Deck &d);

};


#endif //FLIP_DECK_H
