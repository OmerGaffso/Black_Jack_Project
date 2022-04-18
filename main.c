#include "data.h"
#include "lists.h"
#include "betPhase.h"
#include "drawPhase.h"
#include "playerDecision.h"
#include "dealerPhase.h"

int main(void)
{
    unsigned int cash, pot, playerBet;
    bool endGameFlag;
    List deck; 
    List playerHand; 
    List dealerHand;
    int playerHandValue, dealerPhaseCode;
    cash = 1000;
    pot = 0;
    endGameFlag = false;
    
    initList(&playerHand);
    initList(&dealerHand);

    welcomMessege();
    initDeck(&deck);
    
    while(!endGameFlag){ // Game Loop - Ends only when player wants to quit.
        // WE ENTER HERE ON FIRST GAME CYCLE OR AFTER RESET DECK FUNCTION.
        
        if (cash < MIN_BET) {
            printf("Out of cash to make a bet.\nGAME OVER!\n");
            endGameFlag = true;
        }

        printCash(&cash, &pot);
        betPhase(&cash, &pot);
        drawPhase(&deck, &playerHand, &dealerHand);
        playerHandValue = playerDecisionPhase(&playerHand, &deck);
        
        if (playerHandValue == BLACK_JACK) {
            blackJack();
            pot *= BLACK_JACK_MULTIPLIER;
            cash += pot;
            playerBet = 0;
            pot = 0;

            continue; // replace with function that prompts the user if he wants to keep playing (yes/no) and changes the loop flag. 
        }
        else if (playerHandValue == BUST) {
            printf("Bust!\n");
            pot = 0;
            playerBet = 0;

            continue; // replace with function that prompts the user if he wants to keep playing (yes/no) and changes the loop flag. 
        }
        else {
           dealerPhaseCode = dealerDrawPhase(&dealerHand, &deck, playerHandValue);

            if (dealerPhaseCode == 1) {
                printf("Dealer Wins!\n");
                pot = 0;
                playerBet = 0;
                
                continue; // replace with function that prompts the user if he wants to keep playing (yes/no) and changes the loop flag. 
           }
           else if (dealerPhaseCode == BUST) {
                printf("Dealer Bust!\n");
                cash += pot * WIN_BET_MULTIPLIER;
                pot = 0;
                playerBet = 0;

                continue; // replace with function that prompts the user if he wants to keep playing (yes/no) and changes the loop flag. 
           }
           else if (dealerPhaseCode == 0) {
                printf("You Win!\n");
                cash += pot * WIN_BET_MULTIPLIER;
                pot = 0;
                playerBet = 0;

                continue; // replace with function that prompts the user if he wants to keep playing (yes/no) and changes the loop flag. 
           } 
           else {
               printf("Tie!\n");
               playerBet = 0;

               continue; // replace with function that prompts the user if he wants to keep playing (yes/no) and changes the loop flag. 
           }
        }
        
    }
    
    resetDeck(&deck, &playerHand, &dealerHand);
    freeDeck(&deck);

    //TESTS:
    // List d_head; // pointer to the start of the deck
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




