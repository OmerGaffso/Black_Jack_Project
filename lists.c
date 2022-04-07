#include "lists.h"

void initDeck(Card *head) {
    uint8_t value = 0x04;

    for (size_t i = 1; i <= DECKSIZE; i++){
        addNewCard(&head, value);
        value++;
    }
    // printDeck(head); // SEEING INSIDE THE LIST, MAKING SURE IT WORKS.
    
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
        print_bits_u8(temp -> data);
        temp = temp -> next;
    }
}
