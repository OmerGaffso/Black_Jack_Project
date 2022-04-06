#ifndef LISTS_H
#define LISTS_H
/********************************************
*                                           *
 *******************************************/
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
/********************************************
*                                           *
 *******************************************/
#define DECKSIZE 52
#define SUITS_NUMBER 4
#define CARDS_IN_SUIT 13

typedef struct Card{
    uint8_t data;
    struct Card* next;
}Card;

/********************************************
*                                           *
 *******************************************/
void printDeck(Card *);

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
void initDeck(Card *);

/*   ---------------------
    | Function: addNewCard |
     ---------------------
        This function adds the cards to the end of the deck.
 */
void addNewCard(Card *, uint8_t);

#endif



