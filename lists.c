#include "lists.h"

// MAYBE CHANGE THE FILE NAME TO DECK INSTEAD OF LISTS, OR ADD THE RELEVANT FUNCTIONS TO PHASE 1 FILE AND THE OTHERS TO DECK FILE.

void initDeck(List *deck) {
    initList(deck);
    uint8_t value = 0x04;
    Card *newCard;

    for (size_t i = 1; i <= DECKSIZE; i++){
        newCard = createCard(value);
        addCard(deck, newCard);
        value++;
    }
    // printList(head); // SEEING INSIDE THE LIST, MAKING SURE IT WORKS. DELETE BEFORE SUBMITTING.
    
}

void initList(List *list) { // WORKING !
    list -> head = NULL;
    list -> len = 0;
}

Card *createCard(uint8_t val) { // WORKING !
    Card *new_card = (Card*) malloc(sizeof(Card));
    if (new_card == NULL) {
        printf("malloc failed\n");
        return NULL;
    }
    new_card -> data = val;
    new_card -> next = NULL;
    return new_card;
}

void printList(List *list) {  // WORKING !
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

void freeDeck(List *deck) { // WORKING !
    Card *temp = deck -> head;

    while(deck -> head != NULL){
        temp = deck -> head;
        deck -> head = temp -> next;
        free(temp);
        deck -> len--;
    }
}

Card *removeCard(List *list, int pos) {
    Card *temp, *current;
    current = list -> head;
    if (pos == 1) {
        list -> head = current -> next ;
        current -> next = NULL;
        list -> len--;
        return current;
    }
    else if (pos == list -> len) {
        for (size_t i = 1; i < list ->len - 1; i++)
            current = current -> next; // current is now card number 51.
        temp = current -> next; // set temp to last card
        current -> next = NULL; // set the 51th card in the deck as the last card.
        list -> len --;
        return temp;
    }
    else {
        for (size_t i = 1; i != pos - 1; i++)
            current = current -> next; // sets current to (n - 1) card.
        temp = current -> next; // sets temp as the n card.
        current -> next = temp -> next; // removes the nth card from the list.
        temp -> next = NULL; // sets the nth card as standalone card.
        list -> len --;
        return temp;
    }
}

void addCard(List *list, Card *card) {
    card -> next = list -> head;
    list -> head = card;
    list -> len++;
}