/**
	EECE2560: Proj2a
	main.cpp
	Purpose: This main file implements the flip game and creates a single
    Deck object to do so. Currently it only shuffles three times.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 2/11/17
*/

#include "deck.h"

void playFlip()
{

    int draw=1, value;
    double score=0;
    Card playcards;

    // Create a new deck
    Deck *d = new Deck;
    // Print out the entire deck
    std::cout << *d;
    // Inform user of shuffle
    for (int i = 0; i < 3; i++) {
        std::cout << "\n*******************\n"
                "Shuffling\n*******************\n";
        d->shuffle();
    }
    // Print out the deck after shuffle
    std::cout << *d;

    std::cout <<"Implement the while loop" << std::endl;
    int i = 0;


    while ((draw != 0) && (i < 23))
    {

        playcards = d->deal()->nodeValue;
        value = playcards.getValue();

        std::cout<<"The value of the card is " <<playcards
                                               <<std::endl;

        switch (value)
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
                score;
                break;
            case 9:
                score;
                break;
            case 8:
                score;
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
        }
        if (playcards.getSuit() == 2) {
            score += 1;
        }



        std::cout << d->getDeckSize();
        std::cout << std::endl;

        std::cout << "Your total score is: " << score << std::endl;
        std::cout << "Enter 0 to exit or any 1 to deal again. " << std::endl;

        std::cin >> draw;
        std::cout << std::endl;

        if(draw ==0) {
            std::cout<<"You have ended the game with a total score of: "
                     <<score<<std::endl;
        }
        i++;

    }
    std::cout<< "The play cards list: "<<std::endl;
    d->printDeck();
    std::cout<<std::endl;
    d->size();




    // Destructor
    delete d;
    std::cout << "Card assignment";
    Card c1(5, 2);
    Card c2;
    c1 = c2;
    std::cout << c1;
    // END

}

int main() {

    playFlip();
    return 0;
}
