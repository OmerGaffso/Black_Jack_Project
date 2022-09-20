#include "data.h"
#include "lists.h"
#include "betPhase.h"
#include "drawPhase.h"
#include "playersPhase.h"
#include "gameHandle.h"


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

    srand(time(NULL)); // sets the seed for the random number generator
    
    initList(&playerHand);
    initList(&dealerHand);

    welcomMessege();
    initDeck(&deck);

    while(play) { // Game Loop - Ends only when player wants to quit.
        // first game cycle or after resetDeck function 

        printf("Your cash: %u$\tCurrent bet: %u$\n",cash, pot);
        betPhase(&cash, &pot);
        initialDrawPhase(&deck, &playerHand, &dealerHand);
        playerHandValue = playerDecisionPhase(&playerHand, &deck);
            
        if (playerHandValue == BLACK_JACK) blackJack(&cash, &pot, &playerBet);    
        else if (playerHandValue == BUST) playerBust(&cash, &pot, &playerBet);    
        else {
           dealerPhaseCode = dealerDrawPhase(&dealerHand, &deck, playerHandValue);

            switch (dealerPhaseCode) {
            
            case DEALER_RESULT_WIN:
                dealerWin(&cash, &pot, &playerBet);
                break;
            
            case DEALER_RESULT_BUST:
                dealerBust(&cash, &pot, &playerBet);
                break;
            
            case DEALER_RESULT_LOST:
                playerWon(&cash, &pot, &playerBet);
                break;
            
            case DEALER_RESULT_TIE:
                tie(&playerBet);
                break;
            }
        }
        play = userEndGame(cash, pot);
        resetDeck(&deck, &playerHand, &dealerHand); 
        // reset the deck either if the player want to continue or wishes to end the game.
    }
    freeDeck(&deck);

    return 0;
}


