#include "drawPhase.h"

void drawPhase(List *deckP, List *playerP, List *dealerP) {
    printf("in drawPhase\n"); // DELETE
    for (size_t i  = 1; i <= HAND_INIT_SIZE; i++)
        drawRandomCard(deckP, playerP);
    
    // TEST ON DRAW FUNCTION
    // printf("Player hand is:\n"); 
    // printList(playerP);

    for (size_t i = 1; i <= HAND_INIT_SIZE; i++)
        drawRandomCard(deckP, dealerP); // 

    // TEST ON DRAW FUNCTION
    // printf("Dealer hand is:\n"); 
    // printList(dealerP);

    printHand(playerP, 'p');
    printHand(dealerP, 'd');
    
}

void drawRandomCard(List *deckP, List *handP) {
    Card* drawnCard;
    int n = generateRandom(deckP->len); // the random number generated.
    if (deckP == NULL) 
        printf("ERROR: the deck is empty.");

    drawnCard = removeCard(deckP, n);
    addCard(handP, drawnCard);
}

void printHand(List* handP, char handCode){
    Card *temp = handP -> head;
    char *cardSuit, *cardRank;
    size_t i = 1;
    if (handCode == 'p') {
        printf("Player: ");
        while (temp != NULL) {
            cardSuit = getCardSuit(temp -> data);
            cardRank = getCardRank(temp -> data);
            printf("%s of %s", cardSuit, cardRank);
            if (i == 1)
                printf(",\t");
            temp = temp -> next;
        }
        puts("");
    }
    else if (handCode == 'd') {
        printf("Dealer: ");
        cardSuit = getCardSuit(temp -> data);
        cardRank = getCardRank(temp -> data);
        printf("%s of %s,\t???? ????\n", cardSuit, cardRank);
    }
}

int generateRandom(int deckSize) {
    int randomNum = 0;

    srand(time(NULL));
    randomNum = (rand() % deckSize) + 1; // return a random integer between 1 and 52.
    return randomNum;
}

char *getCardRank(uint8_t val) {
    char *rank;
    unsigned int mask = 0x3C; // sets mask to bit pattern 00111100

    memset(&rank, '\0', MAX_NAME_LEN); // initiate the "rank" string as string of 10 characters where all of them are the char '\0'
    mask &= val;
    memcpy(&rank, getRankName(mask), MAX_NAME_LEN);
    // rank = getRankName(mask);
    return rank;

}

char *getCardSuit(uint8_t val) {
    char *suit;
    unsigned int mask = 0x03; // sets mask to bit pattern 00000011

    memset(&suit, '\0', MAX_NAME_LEN); // initiate the "suit" string as string of 10 characters where all of them are the char '\0'
    mask &= val;
    memcpy(&suit, getSuitName(mask), MAX_NAME_LEN);
    // suit = getSuitName(mask);
    return suit;
}
