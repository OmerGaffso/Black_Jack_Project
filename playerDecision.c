#include "playerDecision.h"

void playerDecisionPhase(List *hand) {
    int handVal = 0;

    handVal = calculateHandValue(hand);
}

int calculateHandValue(List *hand) {
    char *cardRank;
    int sum = 0, aceCnt = 0, cardValue = 0;
    uint8_t cardData;
    bool royaltyFlag = false;
    Card *temp = hand -> head;

    if (hand -> head == NULL) {
        printf("ERROR: player hand is empty.\n");
        return -1;
    }

    while(temp != NULL) {
        cardData = extractRankBits(temp -> data);
        cardRank = getRankName(cardData);
        
        if (strcmp(cardRank, "Ace") == 0) { // checks if the rank is Ace, if so, turn on the aceFlag (for use later) and addes 11 to the sum.
            sum += ACE_VALUE;
            aceCnt++;
        }
        else if (royaltyFlag = isRoyalty(cardRank)) { // checks if rank is king/queen/jack. if so, adds 10 to the sum. flag reset on the end of the loop.
            sum += ROYALTY_VALUE;
        }
        else {
            cardValue = atoi(cardRank); // if atoi is successful, card value will have the matching integer (2-9).
            if (cardValue >= 0) { // if cardValue is 0, then atoi failed for some reason.
                sum += cardValue;
            }
            else {
                printf("ERROR: atoi was not able to convert the rank into number.\n");
                return -1;
            }
        }
        royaltyFlag = false;
        temp = temp -> next;
    } // end of while loop

    if (sum == BLACK_JACK) {
        blackJack();
        return BLACK_JACK;
    }
    
    if (sum > BLACK_JACK) { 
        if (aceCnt > 0) { // the sum is over 21, and there is ace in hand
            while (aceCnt > 0) { // run in loop to handle the cases where a hand have more than one ace.
                sum -= ROYALTY_VALUE;
                aceCnt--;
                if (sum == BLACK_JACK) { // for edge cases. for example: the player has Ace Ace 9 - it will be calculated to 31, and if we subtract 10- it is a black jack.
                    blackJack();
                    return BLACK_JACK;
                }
            }
        }
        else {
            printf("Bust!\n"); // the sum is over 21, and there is no aces at hand. 
            return 0;
        }
    }

    return sum; // no special cases or black jack. returns the hand value.
}

bool isRoyalty(char *rank) {
    if(strcmp(rank, "King") == 0 || strcmp(rank, "Queen") == 0 || strcmp(rank, "Jack") == 0)
        return true;
    return false;    
}
