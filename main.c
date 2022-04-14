#include "data.h"
#include "lists.h"
#include "betPhase.h"
#include "drawPhase.h"
#include "playerDecision.h"

// Phase 1
void gameInit(); 
char endGame(); // Add a function that returns end game code. -1 is game over, 1 is keep playing, 0 is finsish game.



int main(void)
{
    // gameInit();

    
    //TESTS:
    List d_head; // pointer to the start of the deck
    // List playerHand, dealerHand;
    // Card *temp, *test;

    // initList(&playerHand);
    // initList(&dealerHand);
    // initDeck(&d_head);
    // printCardsInFormat(&d_head);
    // printf("the deck has %zu cards.\nThe deck is:\n", d_head.len);
    // printList(&d_head);

    // temp = removeCardFromHand(&d_head);
    // addCard(&playerHand, temp);
    // temp = removeCardFromHand(&d_head);
    // addCard(&playerHand, temp);
    // printList(&playerHand); 
    
    // temp = removeCardFromHand(&d_head);
    // addCard(&dealerHand, temp);
    // temp = removeCardFromHand(&d_head);
    // addCard(&dealerHand, temp);
    // printList(&dealerHand);

    // printf("the player have %zu cards.\nthe dealer have %zu cards.\nthe deck now contains %zu cards.\n", playerHand.len, dealerHand.len, d_head.len);
    // // temp = playerHand.head;
    // // test = dealerHand.head;
    // resetDeck(&d_head, &playerHand, &dealerHand);
    
    // puts("");
    // printf("hands after reset\n");
    // printf("player hand:\n");
    // printList(&playerHand);
    // printf("dealer hand:\n");
    // printList(&dealerHand);
    // puts("");
    // printf("deck after reset:\n");
    // printList(&d_head);
    

    // printf("after reset deck:\n");
    // printf("the player have %zu cards.\nthe dealer have %zu cards.\nthe deck now contains %zu cards.\n", playerHand.len, dealerHand.len, d_head.len);
    // freeDeck(&d_head);
    // printList(d_head);
    // freeDeck(&d_head);
    // printList(&d_head);


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
    List d_head; // pointer to the start of the deck
    List playerHand; 
    initList(&playerHand);
    List dealerHand;
    initList(&dealerHand);

    cash = 1000;
    pot = 0;
    endGameFlag = false;

    welcomMessege();
    initDeck(&d_head);
    while(!endGameFlag){ // Game Loop - Ends only when player wants to quit.
        // WE ENTER HERE ON FIRST GAME CYCLE OR AFTER RESET DECK FUNCTION.
        
        printCash(&cash, &pot);
        betPhase(&cash, &pot);
        drawPhase(&d_head, &playerHand, &dealerHand);
        playerDecisionPhase(&playerHand);


        
    }
}

