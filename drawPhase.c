#include "drawPhase.h"

void drawPhase(List *deckP, List *playerP, List *dealerP) {
    // printf("in drawPhase\n"); // DELETE
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
    // printf("before printHand\n");
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
    Card *temp;
    char *cardSuit, *cardRank;
    uint8_t cardData;
    // cardSuit = "\0"; 
    // memset(&cardSuit, '\0', MAX_NAME_LEN);
    // memset(&cardRank, '\0', MAX_NAME_LEN);
    // cardRank = "\0"; 
    temp = handP -> head;
    // printf("in printhand, %c\n", handCode);
    if (handCode == 'p') {
        // printf("in if statement\n"); // TEST
        printf("Player: ");
        while (temp != NULL) {
            // printf("in while loop\n");
            cardData = extractSuitBits(temp -> data);
            cardSuit = getSuitName(cardData);
            // strcpy(cardSuit, getCardSuit(temp -> data));
            strcat(cardSuit, "\0");
            // printf("%s\n", cardSuit);
            // cardRank = getCardRank(temp -> data);
            /* These two lines makes a copy of the card data, and "deletes" the suit bits from the value to extract the card rank */
            cardData = extractRankBits(temp -> data);
            
            // strcpy(cardRank, getCardRank(temp -> data));
            // strcat(cardRank, "\0");
            cardRank = getRankName(cardData);
            printf("%s of %s", cardRank, cardSuit);
            if (temp -> next != NULL)
                printf(",\t");
            temp = temp -> next;
        }
        puts("");
        // printf("ended while loop\n");
    }
    else if (handCode == 'd') {
        cardData = extractSuitBits(temp -> data); 
        cardSuit = getSuitName(cardData);
        // cardSuit = getCardSuit(temp -> data);
        // strcpy(&cardSuit, getCardSuit(temp -> data));
        cardData = extractRankBits(temp -> data);
        cardSuit = getRankName(cardData);
        // cardRank = getCardRank(temp -> data);
        // strcpy(&cardRank, getCardRank(temp -> data));

        printf("%s of %s,\t???? ????\n", cardRank, cardSuit);
    }
}

int generateRandom(int deckSize) {
    int randomNum = 0;

    srand(time(NULL));
    randomNum = (rand() % deckSize) + 1; // return a random integer between 1 and 52.
    return randomNum;
}

uint8_t extractSuitBits(uint8_t cardData) {
    /* These two lines makes a copy of the card data, and "deletes" the non relevant bits from it to extract the card suit. */
    cardData <<= RANK_BITS;
    cardData >>= RANK_BITS;
    return cardData; 
}

uint8_t extractRankBits(uint8_t cardData) {
    cardData >> SUIT_BITS;
    return cardData;
}

// char *getCardRank(uint8_t val) {
//     char *rank;
//     unsigned int mask = 0x3C; // sets mask to bit pattern 00111100

//     // printf("in getCardRank\n");

//     memset(&rank, '\0', MAX_NAME_LEN); // initiate the "rank" string as string of 10 characters where all of them are the char '\0'
//     mask &= val;
//     // strcpy(rank, getRankName(mask));
//     rank = getRankName(mask);
//     // printf("done getCardRank\n");

//     return rank;

// }

// char *getCardSuit(uint8_t val) {
//     char suit[MAX_NAME_LEN];
//     unsigned int mask = 0x03; // sets mask to bit pattern 00000011

//     // printf("in getCardSuit\n");

//     memset(&suit, '\0', MAX_NAME_LEN); // initiate the "suit" string as string of 10 characters where all of them are the char '\0'
//     mask &= val;
//     strcat(suit, getSuitName(mask));
//     strcat(suit, '\0');
//     // printf("suit is %s\n",suit);
//     // suit = getSuitName(mask);
//     // printf("done getCardSuit\n");
//     return *suit;
// }
