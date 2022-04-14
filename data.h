#ifndef DATA_H
#define DATA_H

/*******************************************
*              Includes:                    *
 *******************************************/
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
/*******************************************
*              Defines:                     *
 *******************************************/
#define DECKSIZE 52
#define SUITS_NUMBER 4
#define CARDS_IN_SUIT 13
#define HAND_INIT_SIZE 2
#define MAX_NAME_LEN 10 
#define SUIT_MASK 0x03
#define RANK_MASK 0x3C
#define SUIT_BITS 2
#define RANK_BITS 6         // including bits 6-7 

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
char* getSuitName(enum suits);

/*   -----------------------
    | Function: getRankName |
     -----------------------
        Helper function that receives a rank number and return its name as a string (based on ranks enum).
 */
char* getRankName(enum ranks);

/*   ---------------------------
    | Function: extractSuitBits |
     ---------------------------
        This function recives the card value, return the suit bits (0-1 bits) value. 
        In this function we use bitwise << and >>, to remove the bits that isn't relevant to the suit, meaning that the bit sequence
        returned from this function is in the format: 000000XX.
        We assume (based on the way we initiate the cards) that bits 6-7 will be 0, and bits 0-5 can be anything.
 */
uint8_t extractSuitBits(uint8_t);

/*   ---------------------------
    | Function: extractRankBits |
     ---------------------------
        This function recives the card value, return the rank bits (2-5) value. 
        In this function we use bitwise >>, to remove the bits that isn't relevant to the rank, meaning that the bit sequence
        we received is 00XXXXXX, and the sequence that will return from this function will be in the format 0000XXXX.
        We assume (based on the way we initiate the cards) that bits 6-7 will be 0, and bits 0-5 can be anything.
 */
uint8_t extractRankBits(uint8_t);

void printCardsInFormat(List *);

#endif 