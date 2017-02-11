/**
	EECE2560: Proj2a
	main.cpp
	Purpose: This main file implements the flip game and creates a single
    Deck object to do so. Currently it only shuffles three times.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 2/11/17
*/

#include "deck.h"

int main() {

    // Create a new deck
    Deck d;
    // Print out the entire deck
    std::cout << d;
    // Inform user of shuffle
    for (int i = 0; i < 3 ; i++)
    {
        std::cout << "\n*******************\n"
                "Shuffling\n*******************\n";
        d.shuffle();
    }
    // Print out the deck
    std::cout << d;

    // END
    return 0;
}