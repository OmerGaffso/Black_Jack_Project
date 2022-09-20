#include "drawPhase.h"

void initialDrawPhase(List *deckP, List *playerP, List *dealerP) {

    for (size_t i  = 1; i <= HAND_INIT_SIZE; i++)
        drawRandomCard(deckP, playerP);
    
    for (size_t i = 1; i <= HAND_INIT_SIZE; i++)
        drawRandomCard(deckP, dealerP); 

    printHand(playerP, 'p');
    printHand(dealerP, 'd');
    
}

void drawRandomCard(List *deckP, List *handP) {
    Card* drawnCard;
    if (deckP == NULL) {
        printf("ERROR: the deck is empty.");
        exit(1); // problem with deck initiation
    }
    
    int n = generateRandom(deckP->len); // the random number generated.
    drawnCard = removeCardByPosition(deckP, n);
    addTopCard(handP, drawnCard);
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
         
            cardData = extractRankBits(temp -> data);
            
            cardRank = getRankName(cardData);
            printf("%s of %s", cardRank, cardSuit);
            if (temp -> next != NULL)
                printf(", ");
            temp = temp -> next;
        }
        puts("");
    }
    else if (handCode == 'd') {
        cardData = extractSuitBits(temp -> data); 

        cardSuit = getSuitName(cardData);

        cardData = extractRankBits(temp -> data);

        cardRank = getRankName(cardData);

        printf("Dealer: %s of %s,???? ????\n", cardRank, cardSuit);
    }
}

int generateRandom(int deckSize) {
    int randomNum = 0;

    randomNum = (rand() % deckSize); 
    // return a random integer between 0 and deck length - 1 (52 cards, 0-51).
    return randomNum;
}
