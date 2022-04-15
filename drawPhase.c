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
    temp = handP -> head;
    if (handCode == 'p') {
        printf("Player: ");
        while (temp != NULL) {

            cardData = extractSuitBits(temp -> data);
            
            cardSuit = getSuitName(cardData);
            strcat(cardSuit, "\0");
         
            cardData = extractRankBits(temp -> data);
            
            cardRank = getRankName(cardData);
            printf("%s of %s", cardRank, cardSuit);
            if (temp -> next != NULL)
                printf(",\t");
            temp = temp -> next;
        }
        puts("");
    }
    else if (handCode == 'd') {
        cardData = extractSuitBits(temp -> data); 

        cardSuit = getSuitName(cardData);

        cardData = extractRankBits(temp -> data);

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
