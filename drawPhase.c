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
        printf("Player: ");
        while (temp != NULL) {

            // printf("The bits before extractSuitBits: ");
            // printBits(temp -> data);

            cardData = extractSuitBits(temp -> data);
            
            // printf("The bits after extractSuitBits: ");
            // printBits(cardData);

            cardSuit = getSuitName(cardData);
            strcat(cardSuit, "\0");
         
            /* These two lines makes a copy of the card data, and "deletes" the suit bits from the value to extract the card rank */
            
            // printf("The bits before extractRankBits: ");
            // printBits(temp -> data);
            
            cardData = extractRankBits(temp -> data);
            
            // printf("The bits after extractRankBits: ");
            // printBits(cardData);
            
            cardRank = getRankName(cardData);
            printf("%s of %s", cardRank, cardSuit);
            if (temp -> next != NULL)
                printf(",\t");
            temp = temp -> next;
        }
        puts("");
    }
    else if (handCode == 'd') {
        // printf("The bits before extractSuitBits: ");
        // printBits(temp->data);

        cardData = extractSuitBits(temp -> data); 

        // printf("The bits after extractSuitBits: ");
        // printBits(cardData);

        cardSuit = getSuitName(cardData);

        // printf("The bits before extractRankBits: ");
        // printBits(temp->data);

        cardData = extractRankBits(temp -> data);

        // printf("The bits after extractRankBits: ");
        // printBits(cardData);

        cardRank = getRankName(cardData);

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
    cardData >>= SUIT_BITS;
    return cardData;
}
