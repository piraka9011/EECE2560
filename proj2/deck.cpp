//
// Created by river on 2/2/17.
//

#include "deck.h"

Deck::Deck()
{
    for (int i = 0; i < NUM_SUIT; i++)
    {
        for (int j = 1; j < NUM_VALUE; j++)
        {
            Card c(j, i);
            deck.insertHead(c);
        }
    }
}

void Deck::swap(node<Card> *a, node<Card> *b)
{
    int tempC1r, tempC1s, tempC2r, tempC2s;
    tempC1r = a->nodeValue.getValue(); tempC1s = a->nodeValue.getSuit();
    tempC2r = b->nodeValue.getValue(); tempC2s = b->nodeValue.getSuit();
    a->nodeValue.setValue(tempC2r);    a->nodeValue.setSuit(tempC2s);
    b->nodeValue.setValue(tempC1r);    b->nodeValue.setSuit(tempC1s);
}


void Deck::shuffle()
{
    int rank;
    node<Card>* c1;
    node<Card>* c2;
    srand(time(NULL));
    for (int i = DECK_SIZE - 1; i >=0; i-- )
    {
        rank = rand() % (i+1);
        c1 = deck.getCard(i);    c2 = deck.getCard(rank);
        swap(c1, c2);
    }
}


std::ostream& operator << (std::ostream& os, Deck &d)
{
    // Create iterator to loop through deck
    node<Card> *it = d.getHeadNode();
    for (int i = 0; i < d.getDeckSize(); i++)
    {
        // Print node value
        os << it->nodeValue;
        // Set iterator as next value
        it = it->next;
    }
    return os;
}

