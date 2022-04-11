#include "drawPhase.h"

void drawPhase(Card *deckP, Card*playerP, Card*dealerP) {
    for (size_t i  = 1; i < HAND_INIT_SIZE; i++)
        drawRandomCard(deckP, playerP);
    
    // TEST ON DRAW FUNCTION
    printf("Player hand is:\n"); 
    printList(playerP);

    for (size_t i = 1; i < HAND_INIT_SIZE; i++)
        drawRandomCard(deckP, dealerP); // 

    // TEST ON DRAW FUNCTION
    printf("Dealer hand is:\n"); 
    printList(dealerP);

    printHand(playerP, 'p');
    printHand(dealerP, 'd');
    
}

void drawRandomCard(Card *deckP, Card *handP) {
    Card* drawnCard;
    int n = random(); // the random number generated.
    if (deckP == NULL) 
        printf("ERROR: the deck is empty.");

    drawnCard = removeCard(deckP, n);
    addCard(handP, drawnCard);
}

void printHand(Card* handP, char handCode){
    
}

int random() {
    static int deckSize = DECKSIZE;
    int randomNum = 0;


    srand(time(NULL));
    randomNum = (rand() % deckSize) + 1; // return a random integer between 1 and 52.
    deckSize--;
    return randomNum;
}
