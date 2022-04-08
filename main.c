#include "data.h"
#include "lists.h"
#include "betPhase.h"
#include "drawPhase.h"

// Phase 1
void gameInit(); 
char endGame(); // Add a function that returns end game code. -1 is game over, 1 is keep playing, 0 is finsish game.



int main(void)
{
    gameInit();
    
    //TEST for card initiation.
    // Card *d_head = NULL; // pointer to the start of the deck
    // initDeck(d_head);

    //TEST for extern global variables:
    // unsigned int cash = 1000;
    // unsigned int pot = 20;
    // printCash(&cash, &pot);

    return 0;
}

// The only function that should be in main file. It is the initiation phase.
/*   --------------------
    | Function: gameInit |
     --------------------
        This function is phase 1 of the game. 
        From this function, we call the functions to introduce the game to the user, and initiate everything we need for a solid game of black jack.
        We will enter the game endless loop in this function, until we get input from user that he wants to end the game.
 */
void gameInit() {
    unsigned int cash, pot;
    bool endGameFlag;
    Card *d_head = NULL; // pointer to the start of the deck
    Card *playerHand = NULL; 
    Card *dealerHand = NULL;

    cash = 1000;
    pot = 0;
    endGameFlag = false;

    welcomMessege();
    initDeck(d_head);
    while(!endGameFlag){ // Game Loop - Ends only when player wants to quit.
        // WE ENTER HERE ON FIRST GAME CYCLE OR AFTER RESET DECK FUNCTION.
        
        printCash(&cash, &pot);
        betPhase(&cash, &pot);
        drawPhase(d_head, playerHand, dealerHand);



        
    }
}

