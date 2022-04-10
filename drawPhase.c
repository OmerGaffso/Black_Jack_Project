#include "drawPhase.h"

void drawPhase(Card *deckP, Card*playerP, Card*dealerP) {
    for (size_t i  = 1; i < HAND_INIT_SIZE; i++)
        drawRandomCard(deckP, playerP);

    for (size_t i = 1; i < HAND_INIT_SIZE; i++)
        drawRandomCard(deckP, dealerP);

    
}

void drawRandomCard(Card* deckP, Card* handP) {
    Card* temp = deckP;
    int n = random(); // the random number generated.
    if (deckP == NULL) 
        printf("ERROR: the deck is empty.");

    Card* newCard;
    newCard = malloc(sizeof(Card));    
    if(handP == NULL) {
        if (n == 1) {
            newCard -> data = deckP -> data;
            deckP = deckP -> next;
            free(temp);
        } else if(n == DECKSIZE) {
            for( size_t i = 1; i != DECKSIZE - 1; i++){ // run until 1 card before the end of the deck, set last card to the hand, and make the carr->next =NULL

            }
            
        }
        newCard -> next = NULL;
    }
    
}

void printHand(Card* handP, int handCode){

}

int random() {
    int randomNum = 0;

    srand(time(NULL));
    randomNum = (rand() % DECKSIZE) + 1; // return a random integer between 1 and 52.
    return randomNum;
}
