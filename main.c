#include "data.h"
#include "lists.h"
#include "betPhase.h"
#include "drawPhase.h"
#include "playerDecision.h"
#include "dealerPhase.h"

int main(void)
{
    unsigned int cash, pot, playerBet;
    bool play;
    List deck; 
    List playerHand; 
    List dealerHand;
    int playerHandValue, dealerPhaseCode;
    cash = 1000;
    pot = 0;
    play = true;
    
    initList(&playerHand);
    initList(&dealerHand);

    welcomMessege();
    initDeck(&deck);
    
    // TEST
    printList(&deck);  
    printCardsInFormat(&deck);
    // END TEST
    
    while(play){ // Game Loop - Ends only when player wants to quit.
        // first game cycle or after resetDeck function 
        
        if (cash < MIN_BET) {
            printf("Out of cash to make a bet.\nGAME OVER!\n");
            play = false;
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

            play = userEndGame(); // prompts the user if he/she wishes to continue playing
        }
        else if (playerHandValue == BUST) {
            printf("Bust!\n");
            pot = 0;
            playerBet = 0;

            play = userEndGame(); // prompts the user if he/she wishes to continue playing
        }
        else {
           dealerPhaseCode = dealerDrawPhase(&dealerHand, &deck, playerHandValue);

            if (dealerPhaseCode == DEALER_WIN) {
                printf("Dealer Wins!\n");
                pot = 0;
                playerBet = 0;

                play = userEndGame(); // prompts the user if he/she wishes to continue playing         
           }
           else if (dealerPhaseCode == BUST) {
                printf("Dealer Bust!\n");
                cash += pot * WIN_BET_MULTIPLIER;
                pot = 0;
                playerBet = 0;

                play = userEndGame(); // prompts the user if he/she wishes to continue playing
           }
           else if (dealerPhaseCode == DEALER_LOST) {
                printf("You Win!\n");
                cash += pot * WIN_BET_MULTIPLIER;
                pot = 0;
                playerBet = 0;
             
                play = userEndGame(); // prompts the user if he/she wishes to continue playing
           } 
           else {
                printf("Tie!\n");
                playerBet = 0;
           
                play = userEndGame(); // prompts the user if he/she wishes to continue playing
           }
        }

        resetDeck(&deck, &playerHand, &dealerHand); // reset the deck either if the player want to continue or wishes to end the game.
    }
    
    freeDeck(&deck);

    return 0;
}