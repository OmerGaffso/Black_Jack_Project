#include "lists.h"

// MAYBE CHANGE THE FILE NAME TO DECK INSTEAD OF LISTS, OR ADD THE RELEVANT FUNCTIONS TO PHASE 1 FILE AND THE OTHERS TO DECK FILE.

void initDeck(Card *head) {
    uint8_t value = 0x04;

    for (size_t i = 1; i <= DECKSIZE; i++){
        addNewCard(&head, value);
        value++;
    }
    // printDeck(head); // SEEING INSIDE THE LIST, MAKING SURE IT WORKS. DELETE BEFORE SUBMITTING.
    
}

void addNewCard(Card **head, uint8_t val) { // WORKING !
    Card *new_card = malloc(sizeof(Card));
    new_card -> data = val;
    new_card -> next = NULL;
    
    if (*head == NULL) {
        *head = new_card;
        return;        
    } 
    else {
        Card *temp = *head;
      
        while(temp -> next != NULL) {
            temp = temp -> next;    
        }
        temp -> next = new_card;
    }
}

void printDeck(Card *d_head) {  // WORKING !
    Card *temp = d_head;
    int count = 1;
    while(temp != NULL){
        printf("%2d = ", count++);
        printBits(temp -> data);
        temp = temp -> next;
    }
}

void freeDeck(Card *d_head) {
    Card *temp;

    while(d_head != NULL){
        temp = d_head;
        d_head = d_head ->next;
        free(temp);
    }
}
