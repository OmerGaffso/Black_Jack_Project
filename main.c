#include "data.h"
#include "lists.h"
#include "betPhase.h"
#include "drawPhase.h"
#include "playerDecision.h"
#include "dealerPhase.h"
#include "gameHandle.h"

void freeMemory(List *, List *, List *);

int main(void) {
    unsigned int cash, pot, playerBet;
    bool play;
    List deck; 
    List playerHand; 
    List dealerHand;
    int playerHandValue, dealerPhaseCode;
    cash = INITAIL_CASH;
    pot = 0;
    play = true;
    
    initList(&playerHand);
    initList(&dealerHand);

    welcomMessege();
    initDeck(&deck);

    while(play) { // Game Loop - Ends only when player wants to quit.
        // first game cycle or after resetDeck function 

        printCash(&cash, &pot);
        betPhase(&cash, &pot);
        drawPhase(&deck, &playerHand, &dealerHand);
        playerHandValue = playerDecisionPhase(&playerHand, &deck);
            
        if (playerHandValue == BLACK_JACK) blackJack(&cash, &pot, &playerBet, &play);    
        else if (playerHandValue == BUST) playerBust(&cash, &pot, &playerBet, &play);    
        else {
           dealerPhaseCode = dealerDrawPhase(&dealerHand, &deck, playerHandValue);

            switch (dealerPhaseCode) {
            
            case DEALER_WIN:
                dealerWin(&cash, &pot, &playerBet, &play);
                break;
            
            case BUST:
                dealerBust(&cash, &pot, &playerBet, &play);
                break;
            
            case DEALER_LOST:
                playerWon(&cash, &pot, &playerBet, &play);
                break;
            
            case TIE:
                tie(&playerBet, &play);
                break;
            }
        }
        
        resetDeck(&deck, &playerHand, &dealerHand); // reset the deck either if the player want to continue or wishes to end the game.
    }
    printf("You chose to end the game.\nHope you enjoyed playing!\n");
    freeDeck(&deck);

    return 0;
}


