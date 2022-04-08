#ifndef DATA_H
#define DATA_H

/*******************************************
*              Includes:                    *
 *******************************************/
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h> 
/*******************************************
*              Defines:                     *
 *******************************************/
#define DECKSIZE 52
#define SUITS_NUMBER 4
#define CARDS_IN_SUIT 13

typedef struct Card{
    uint8_t data;
    struct Card* next;
}Card;

/*******************************************
*              Prototypes:                  *
 *******************************************/
// These are helper functions, used mainly for general purposes or testing.

/*   ---------------------
    | Function: printBits |
     ---------------------
        This function receives a number of type uint8_t, and prints the bit sequence of the value. 
 */
void printBits(uint8_t num);

/*   -------------------------
    | Function: welcomMessege |
     -------------------------
        This function introduce the game to the player. 
 */
void welcomMessege();

/*   ---------------------
    | Function: printCash |
     ---------------------
        Helper function to make printing cash and bet easier.
 */
void printCash(unsigned int *, unsigned int *);

#endif 