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
#define HAND_INIT_SIZE 2
#define MAX_NAME_LEN 10 

typedef struct Card{
    uint8_t data;
    struct Card* next;
}Card;

typedef struct List {
    struct Card *head;
    size_t len;
}List;

enum suits{Diamonds, Clubs, Hearts, Spades} Suit;

enum ranks{Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King} Rank;

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

/*   -----------------------
    | Function: getSuitName |
     -----------------------
        Helper function that receives a suit number and return its name as a string (based on suits enum).
 */
const char* getSuitName(enum suits);

/*   -----------------------
    | Function: getRankName |
     -----------------------
        Helper function that receives a rank number and return its name as a string (based on ranks enum).
 */
const char* getRankName(enum ranks);

#endif 