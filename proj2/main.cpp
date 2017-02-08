#include <iostream>

#include "deck.h"

int main() {

    Deck *d = new Deck;
    std::cout << d;
    std::cout << "test";
    std::cout << d;
//    std::cout << "\n*******************\n"
//                "Shuffling\n*******************\n";
//    d->shuffle();
//    std::cout << d;

    return 0;
}