#include "playersPhase.h"

int playerDecisionPhase(List *hand, List *deck) {
    int handVal = 0;
    char decision[MAX_NAME_LEN]; 
    bool standFlag = false;

    handVal = calculateHandValue(hand);
    if (handVal == BLACK_JACK) {
        return BLACK_JACK;
    }
    printHandValue(handVal, true);

    while (!standFlag) {

        printf("Will you hit or stand? (write hit/stand):\n");
        scanf(" %s", decision);

        toLower(decision);
        
        if (strcmp(decision, "hit") == 0) { // draw a new card and calaculate the new hand value.
            drawRandomCard(deck, hand);
            printHand(hand, true, true);
            handVal = calculateHandValue(hand);
            if (handVal == BLACK_JACK) 
                return BLACK_JACK;
            else if (handVal == BUST) 
                return BUST;
            else {
                printHandValue(handVal, true);
                continue; // if the hand value is not blackjack or bust, return to player decision (input)
            }
        }
        else if (strcmp(decision, "stand") == 0) {
            standFlag = true; // breakes the loop and returns the hand vlaue.
        }
        else {
            printf("Invalid input. <hit/stand>\n");
        }
    }
    return handVal;
}

int calculateHandValue(List *hand) {
    int sum = 0, aceCnt = 0;
    uint8_t rankValue;
    Card *temp = hand -> head;

    /*
        hand shouldn't be empty in this stage. 
        in order to check the hand value as it fills, comment out this if statement
    */
    if (hand -> head == NULL) {
        printf("ERROR: player hand is empty.\n");
        exit(1); 
    }

    while(temp != NULL) {
        rankValue = extractRankBits(temp -> data);
        
        if (rankValue == Ace) { // checks if the rank is Ace. 
            sum += ACE_VALUE;
            aceCnt++; // count of aces in hand, for calculating the hand value.
        }
        else if (rankValue > Ten) { // checks if rank is king/queen/jack. if so, adds 10 to the sum. 
            sum += ROYALTY_VALUE;
        }
        else {
            //  1 < rankValue <= 10 now
            sum += rankValue;
        }
        temp = temp -> next;
    } // end of while loop

    /* 
        if there are aces in the hand, and the hand value is greater than 21, 
        subtract 10 from the hand value to get the maximum hand value that isn't a bust
        (as long as there are aces in the hand)
    */
    while(aceCnt > 0 && sum > BLACK_JACK) { 
        --aceCnt;
        sum -= ACE_BONUS;
    }

    /*
        for edge cases. subtracted aces from sum, and the sum is still greater than 21.
        for example: we draw ace, ace, ace, king, 9. even if we subtract 30 from hand value, 
        we still end up with value of 22 which is a bust.  
    */
    if (sum > BLACK_JACK) 
        return BUST;
    else
        return sum; 
}

void printHandValue(int handVal, bool isPlayer) {
    if (isPlayer) {
        printf("Your currnet hand value is: %d\n", handVal);
    } else {
        printf("The dealer stands. His hand value is: %d\n", handVal);
    }
}

int dealerDrawPhase(List *dealerHand, List *deck, int dealerHandVal, int playerHandVal) {
    
    // in this stage there is no need to check for bust, because the dealers
    // hand contains only two cards.

    while (dealerHandVal < MIN_DEALER_HAND_VAL && dealerHandVal <= playerHandVal) {
        drawRandomCard(deck, dealerHand);
        dealerHandVal = calculateHandValue(dealerHand);

        if (dealerHandVal == BUST) {
            printHand(dealerHand, false, true);
            return DEALER_RESULT_BUST;
        }
    }
    printHand(dealerHand, false, true);
    printHandValue(dealerHandVal, false);
    if (dealerHandVal > playerHandVal) return DEALER_RESULT_WIN;
    else if (dealerHandVal < playerHandVal) return DEALER_RESULT_LOST;
    else return DEALER_RESULT_TIE;
}