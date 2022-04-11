#include "lists.h"

// MAYBE CHANGE THE FILE NAME TO DECK INSTEAD OF LISTS, OR ADD THE RELEVANT FUNCTIONS TO PHASE 1 FILE AND THE OTHERS TO DECK FILE.

void initDeck(Card *head) {
    uint8_t value = 0x04;

    for (size_t i = 1; i <= DECKSIZE; i++){
        createCard(&head, value);
        value++;
    }
    // printList(head); // SEEING INSIDE THE LIST, MAKING SURE IT WORKS. DELETE BEFORE SUBMITTING.
    
}

void createCard(Card **head, uint8_t val) { // WORKING !
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

void printList(Card *d_head) {  // WORKING !
    Card *temp = d_head;
    int count = 1;
    if (d_head == NULL) {
        printf("The list is empty.\n");
        return;
    }
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

Card *removeCard(Card **list, int pos) {
    Card *temp, *current;
    current = list;
    if (pos == 1) {
        list = current -> next ;
        current -> next = NULL;
        return current;
    }
    else if (pos == DECKSIZE) {
        for (size_t i = 1; i < DECKSIZE - 1; i++)
            current = current -> next;
        temp = current -> next; // set temp to last card
        current -> next = NULL; // set the 1 card before old last as the last card.
        return temp;
    }
    else {
        for (size_t i = 1; i != pos - 1; i++)
            current = current -> next;
        temp = current -> next;
        current -> next = temp -> next;
        temp -> next = NULL;
        return temp;
    }
}

void addCard(Card *hand, Card *card) {
    if (hand == NULL)
        hand = card;
    else {
        Card *temp;
        temp = hand;
        while(temp != NULL)
            temp = temp -> next;
        temp -> next = card;
    }     
}