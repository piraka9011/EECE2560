//
// Created by river on 2/2/17.
//

#include "deck.h"

Deck::Deck()
{
    Card newCard;
    for (int i = 0; i < NUM_SUIT; i++)
    {
        newCard.setSuit(i);
        for (int j = 0; j < NUM_VALUE; j++)
        {
            newCard.setValue(j);
            deck.push_back(newCard);
        }
    }
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

std::ostream& operator << (std::ostream& os, const Deck deck)
{
    for (int i = 0; i < DECK_SIZE; i++)
        os << deck.at(i);
}
