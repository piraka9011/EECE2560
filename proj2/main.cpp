/**
	EECE2560: Proj2a
	main.cpp
	Purpose: This main file implements the flip game and creates a single
    Deck object to do so. Currently it only shuffles three times.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 2/11/17
*/

#include "deck.h"

/**
    The playFlip function is the games main function that implements the game
    and is the only function called in main. It is a global function and
    utilizes the Deck, Card, and LinkedList classes.
 */
void playFlip()
{
    // Init vars and params
    int draw = 1, choice = 1, cardChoice, lastCardChoice = 0;
    double score=0;
    node<Card>* card;
    // Create a new deck
    Deck *d = new Deck;

    // Inform user of shuffle
    for (int i = 0; i < 3; i++) {
        std::cout << "\n*******************\n"
                "Shuffling\n*******************\n";
        d->shuffle();
    }

    /// Debugging only
    // std::cout << "Initially shuffled deck: \n" << *d << std::endl;

    // Get top 24 cards
    LinkedList gameDeck;
    for (int i = 0; i < 23; i++)
    {
        gameDeck.replace(d->deal()->nodeValue);
    }

    //Print top 24 cards
    std::cout << "Top 24 cards:\n";
    std::cout << gameDeck << std::endl;
    // Print cards in deck
    std::cout << "Remaining cards:\n";
    std::cout << *d;

    // Loop until user no longer wishes to play (draw == 0)
    while (draw)
    {
        // Prompt user to select card
        std::cout << "Select a card to turn over (1-24)\n";
        std::cin >> cardChoice;

        // Conduct check to see if user selected same card 3 times
        if (cardChoice == lastCardChoice)
        {
            choice++;
            if (choice == 3)
            {
                std::cout << "You have chosen that card three times in a row!\n"
                          << "Select another card maybe?\n";
            }

        }

        // Get card user selected
        card = gameDeck.getCard(cardChoice-1);
        std::cout << "Your card is:\n" << card->nodeValue
                  << std::endl;

        // Adjust user score accordingly
        switch (card->nodeValue.getValue())
        {
            case 1:
                score += 10;
                break;
            case 11:
                score += 5;
                break;
            case 12:
                score += 5;
                break;
            case 13:
                score += 5;
                break;
            case 10:
                break;
            case 9:
                break;
            case 8:
                break;
            case 7:
                score = score / 2;
                break;
            case 6:
                score = 0;
                break;
            case 5:
                score = 0;
                break;
            case 4:
                score = 0;
                break;
            case 3:
                score = 0;
                break;
            case 2:
                score = 0;
                break;
            default:
                std::cout << "ERROR!\n";
                break;
        }
        if (card->nodeValue.getSuit() == 2)
            score += 1;

        // Print score and continuation prompt
        std::cout << "Your total score is: " << score << std::endl;
        std::cout << "Enter 0 to exit or 1 to deal again. " << std::endl;
        std::cin >> draw;

        // Set users previous card choice
        lastCardChoice = cardChoice;
    }

    // End Game
    std::cout<<"You have ended the game with a total score of: "
             << score << std::endl;

    // Destructor
    delete d;
}

int main() {
    // Play the game
    playFlip();
    // End of program
    return 0;
}
