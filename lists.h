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
        Used in testing and debugging.
        Helper function that prints the deck content (prints the bit sequence of the cards in the list).
        parameters:
            List * - The list head pointer to be printed.
 */
void printList(List *);

/*   ---------------------
    | Function: initDeck |
     ---------------------
        This function create the cards unique bit sequence.
        It will create 52 cards, 13 cards for each suit- spades, diamonds, hearts and clubs.
        Bits 0-1 will indicate the suit of the card-    11 = spades
                                                        10 = hearts
                                                        01 = clubs
                                                        00 = diamonds
        bits 2-5 will indicate the rank of the card-    0001 = Ace
                                                        ...
                                                        ...
                                                        ...
                                                        1101 = King
        bits 6-7 will indicate nothing about the card.
        for example: 01110101 = King of Clubs.
        At the end of the function, we will have a full deck.
        parameters:
            List * - the list head pointer that will be the deck. the cards that will be created will be added to this list.  
 */
void initDeck(List *);

/*   ---------------------
    | Function: removeCard |
     ---------------------
        This function removes a card from position, and returns the card (used for drawing a card from the deck).
        Parameters:
            List * - Pointer to the list the card will be removed from
            int - The index of the card to remove
        Returns:
            Card * - The card that has been removed
 */
Card*removeCard(List *, int);

/*   ------------------------------
    | Function: removeCardFromHand |
     ------------------------------
        This function removes the first card from the passed List, and returns the card (used for reseting the hands).
        Parameters:
            List * - Pointer to the list from which to remove the card
        Returns:
            Card * - The card that was removed
 */
Card*removeCardFromHand(List *); 

/*   ---------------------
    | Function: createCard |
     ---------------------
        This function creates a Card node and sets its value.
        Parameters:
            uint8_t - The bit pattern for the card value (contains rank and suit).
        Returns:
            Card * - The card that was created
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
        Parameters:
            List * - The list to add the card to
            Card * - The card to add to the given list
 */
void addCard(List*, Card*);

/*   ---------------------
    | Function: initList  |
     ---------------------
        This function initiate a list with initial values of head = NULL and Len = 0.
        Parameters:
            List * - A list to initiate
 */
void initList(List *list);

/*   ----------------------
    | Function: resetDeck  |
     ----------------------
        This function returns all of the drawn cards to the deck. 
        Used at the end of the game loop in preparation to initiate a new game or for freeing the malloced cards.
        Parameters:
            List * - The deck
            List * - The player hand
            List * - The dealer hand
 */
void resetDeck(List *, List *, List *);
#endif



