#ifndef LISTS_H
#define LISTS_H
/*******************************************
*              Includes:                    *
 *******************************************/
#include "data.h"

/*******************************************
*              Prototypes:                  *
 *******************************************/
/*   ---------------------
    | Function: printList |
     ---------------------
        Helper function that prints the deck content.
 */
void printList(List *);

/*   ---------------------
    | Function: initDeck |
     ---------------------
        This function create the cards unique bit sequence.
        It will create 52 cards, 13 cards for each suit- spades, diamonds, hearts and clubs.
        Bits 0-1 will indicate the suit of the card-    00 = spades
                                                        01 = hearts
                                                        10 = clubs
                                                        11 = diamonds
        bits 2-5 will indicate the rank of the card-    0001 = Ace
                                                        ...
                                                        ...
                                                        ...
                                                        1101 = King
        bits 6-7 will indicate nothing about the card.
        for example: 01110101 = King of hearts.
        At the end of the function, we will have a full deck.  
 */
void initDeck(List *);

/*   ---------------------
    | Function: removeCard |
     ---------------------
        This function removes a card from position, and returns the card.
        Receives as parameters Card list to remove the card from, and an int that indicates the position of the card to remove.
 */
Card*removeCard(List *, int);

/*   ------------------------------
    | Function: removeCardFromHand |
     ------------------------------
        This function removes the first card from the passed List, and returns the card.
        Receives as parameters Card list to remove the card from.
        Returns the card that was removed.
 */
Card*removeCardFromHand(List *); 

/*   ---------------------
    | Function: createCard |
     ---------------------
        This function create the cards and add them to the deck.
 */
Card* createCard(uint8_t);

/*   ---------------------
    | Function: freeDeck  |
     ---------------------
        This function frees the memory used in the deck linked list.
 */
void freeDeck(List *);

/*   ---------------------
    | Function: addCard  |
     ---------------------
        This function receives a card and a list, and pushes the card to the start of the given list.
        Receives List to push to and a Card to push as parameters.
 */
void addCard(List*, Card*);

/*   ---------------------
    | Function: initList  |
     ---------------------
        This function initiate a list to null and len 0.
        Receives a list pointer to initiate the list.
 */
void initList(List *list);

/*   ----------------------
    | Function: resetDeck  |
     ----------------------
        This function initiate a list to null and len 0.
        Receives a list pointer to initiate the list.
 */
void resetDeck(List *, List *, List *);
#endif



