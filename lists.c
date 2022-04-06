#include "lists.h"

void initDeck(Card *head) {
    // uint8_t value = 0x00;
    // uint8_t mask = 0x00;
    // size_t n = 2;

    // for (size_t i = 0; i < DECKSIZE; i++){ 
        
    //     for (size_t j = 0; j < CARDS_IN_SUIT; j++) {
    //         mask |= 1 << (n + j);
    //         value |= mask;
    //         addNewCard(head,tail, value);
    //     }
    // }
    for (uint8_t i = 1; i <= DECKSIZE; i++){
        addNewCard(head, i);
    }
    printDeck(head);
}

void addNewCard(Card *head, uint8_t val) {
    Card *new_card = malloc(sizeof(Card));
    new_card -> data = val;
    new_card -> next = NULL;

    if (head == NULL){ // Deck is empty, adding first card
        head = new_card;
        printf("head: %u\n", head -> data);
    }
    else { // Deck is not empty, adding card to the end of the Deck.
        Card *temp = head;

        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = new_card;
    } 
}

void printDeck(Card *d_head) {
    Card *temp = d_head;
    // printf("head: %u\n", d_head -> data);
    while(temp != NULL){
        printf("%u\n", temp -> data);
        temp = temp -> next;
    }
}