#include "dealerPhase.h"

int dealerDrawPhase(List *dealerHand, List *deck, int playerHandVal) {
    int handVal = 0;

    handVal = calculateHandValue(dealerHand); 

    if (handVal > playerHandVal) return 1;
    
    else {
       
        while(true) {
            drawRandomCard(deck, dealerHand);
            handVal = calculateHandValue(dealerHand);

            if (handVal > BLACK_JACK) return BUST;
            else if (handVal > playerHandVal && handVal <= BLACK_JACK) return 1;
            else if (handVal > MIN_DEALER_HAND_VAL && handVal <= BLACK_JACK) { // if the dealer hand value is not yet greater than 17, keeps on going.      
                if (handVal < playerHandVal) return 0; // dealer lost
                else if (handVal == playerHandVal) return handVal; // tie
            }
        }
    }
}