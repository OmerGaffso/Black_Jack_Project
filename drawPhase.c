#include "drawPhase.h"

void drawPhase(List *deckP, List *playerP, List *dealerP) {
    printf("in drawPhase\n"); // DELETE
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

void drawRandomCard(List *deckP, List *handP) {
    Card* drawnCard;
    int n = generateRandom(); // the random number generated.
    if (deckP == NULL) 
        printf("ERROR: the deck is empty.");

    drawnCard = removeCard(deckP, n);
    addCard(handP, drawnCard);
}

void printHand(List* handP, char handCode){

}

int generateRandom() {
    static int deckSize = DECKSIZE;
    int randomNum = 0;


    srand(time(NULL));
    randomNum = (rand() % deckSize) + 1; // return a random integer between 1 and 52.
    deckSize--;
    return randomNum;
}
