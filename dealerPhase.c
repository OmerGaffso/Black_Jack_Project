#include "dealerPhase.h"

int dealerDrawPhase(List *dealerHand, List *deck, int playerHandVal) {
    int handVal = 0;

    handVal = calculateHandValue(dealerHand); 

    if (handVal > playerHandVal) return DEALER_WIN;
    
    else {
       
        while(true) {
            drawRandomCard(deck, dealerHand);
            handVal = calculateHandValue(dealerHand);

            if (handVal == BUST) return BUST;
            else if (handVal > playerHandVal && handVal <= BLACK_JACK) return DEALER_WIN;
            else if (handVal >= MIN_DEALER_HAND_VAL && handVal <= BLACK_JACK) { // if the dealer hand value is not yet greater than 17, keeps on going.      
                if (handVal < playerHandVal) return DEALER_LOST; // dealer lost
                else if (handVal == playerHandVal) return TIE; // tie
            }
        }
    }
}