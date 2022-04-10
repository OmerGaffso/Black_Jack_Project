#include "drawPhase.h"

void drawPhase(Card *deckP, Card*playerP, Card*dealerP) {
    for (size_t i  = 1; i < HAND_INIT_SIZE; i++)
        drawRandomCard(deckP, playerP);

    for (size_t i = 1; i < HAND_INIT_SIZE; i++)
        drawRandomCard(deckP, dealerP);

    
}

void drawRandomCard(Card *deckP, Card *handP) {
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
        } 
        else if(n == DECKSIZE) {
            for( size_t i = 1; i != DECKSIZE - 1; i++) // run until 1 card before the end of the deck.
                temp = temp -> next; 
            newCard = temp -> next; // set newCard to the last card
            temp -> next = NULL; // set the 1 card before old last as the last card.
        }
        else {
            for( size_t i = 1; i < n; i++) // go's to one card before the nth card
                temp = temp -> next;
            newCard = temp -> next; // set newCard as the nth card.
            temp -> next = newCard -> next; // "deletes" the nth card from the deck after moving it to the hand.
        }
        newCard -> next = NULL;
    }
    
}

void printHand(Card* handP, int handCode){

}

int random() {
    static int deckSize = DECKSIZE;
    int randomNum = 0;


    srand(time(NULL));
    randomNum = (rand() % deckSize) + 1; // return a random integer between 1 and 52.
    deckSize--;
    return randomNum;
}
