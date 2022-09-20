#include "lists.h"

void initDeck(List *deck) {
    initList(deck);
    Card *newCard;
    uint8_t value = FIRST_CARD_BITS;


    for (size_t i = 1; i <= DECKSIZE; i++){
        newCard = createCard(value);
        addTopCard(deck, newCard);
        value++;
    }    
}

void initList(List *list) { 
    list -> head = NULL;
    list -> len = 0;
}

Card *createCard(uint8_t val) { 
    Card *new_card = (Card*) malloc(sizeof(Card));
    if (new_card == NULL) {
        printf("ERROR: malloc failed\n");
        exit(1); // malloc failed, exit program
    }
    new_card -> data = val;
    new_card -> next = NULL;
    return new_card;
}

void printList(List *list) {  
    if (list -> head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Card *temp = list -> head;
    int count = 1;
    while(temp != NULL){
        printf("%2d = ", count++);
        printBits(temp -> data);
        temp = temp -> next;
    }
}

void freeDeck(List *deck) { 
    Card *temp = deck -> head;

    while(deck -> head != NULL){
        temp = deck -> head;
        deck -> head = temp -> next;
        free(temp);
        deck -> len--;
    }
}

Card *removeCardByPosition(List *list, int pos) {
    Card *prev = NULL;
    Card *curr = list->head;
    
    while(pos--) { // sets curr to the card at pos, and prev to the card at pos - 1
        prev = curr;
        curr = curr -> next;
    }

    if (prev) 
        prev -> next = curr -> next; // prev != NULL, so pos is between 1 and list length - 1.
    else 
        list -> head = curr -> next; 
        // prev == NULL, meaning pos == 0. moves the list head to the card at pos 1.

    list -> len -- ;
    curr -> next = NULL;
    return curr;
}

void addTopCard(List *list, Card *card) {
    card -> next = list -> head;
    list -> head = card;
    list -> len++;
}

void resetDeck(List *deck, List *playerHand, List *dealerHand) {
    Card *temp;

    while (playerHand -> head != NULL) {
        temp = removeTopCard(playerHand);
        addTopCard(deck, temp);
    }

    while (dealerHand -> head != NULL) {
        temp = removeTopCard(dealerHand);
        addTopCard(deck, temp);
    }
}

Card*removeTopCard(List *list) {
    Card *current = list -> head;
    if (current == NULL) return NULL;
    list -> head = current -> next;
    current -> next = NULL;
    list -> len--;
    return current;
}
