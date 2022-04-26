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
#include <ctype.h>

/*******************************************
*              Defines:                     *
 *******************************************/
#define INITAIL_CASH 1000           
#define DECKSIZE 52                 // number of cards in the deck
#define SUITS_NUMBER 4              // number of suits in a deck of cards
#define CARDS_IN_SUIT 13            // number of cards per suit
#define HAND_INIT_SIZE 2            // number of card per hand in the beginning of a black jack roun
#define MAX_NAME_LEN 10             // maximum size of rank/suit length (used for initiating strings throughout the game)
#define SUIT_BITS 2                 // number of bits that represent the suit in a uint8_t variable
#define RANK_BITS 6                 // number of bits that represent the rank in a uint8_t variable (including bits 6-7) 
#define BLACK_JACK 21               // value that represents Black Jack
#define BUST -1                     // value that represent the situation of player/dealer has hand value larger than 21
#define BLACK_JACK_MULTIPLIER 2.5   // multiplier of black jack
#define WIN_BET_MULTIPLIER 2        // multiplier of regular win 
#define MIN_BET 10                  // minimum cash to make a bet
#define FIRST_CARD_BITS 0x04        // uesd to initates the first card bit sequence to 00000100


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
        $$$$$   Used in testing and debugging.  $$$$$
        This function prints the bit sequence of the received value.
        Parameters:
            uint8_t - The value to print 
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
        Helper function that prints the player cash and the bet pool.
        Parameters:
            unsigned int * - The player cash pool
            unsigned int * - The bet pool
 */
void printCash(unsigned int *, unsigned int *);

/*   -----------------------
    | Function: getSuitName |
     -----------------------
        Helper function that receives a suit number and return its name as a string (based on suits enum).
        Parameters:
            enum suits - the suit number 
        Returns:
            char * - the suit name
 */
char* getSuitName(enum suits);

/*   -----------------------
    | Function: getRankName |
     -----------------------
        Helper function that receives a rank number and return its name as a string (based on ranks enum).
        Parameters:
            enum ranks - the rank number 
        Returns:
            char * - the rank name (or digit)
 */
char* getRankName(enum ranks);

/*   ---------------------------
    | Function: extractSuitBits |
     ---------------------------
        This function recives the card value, return the suit bits (0-1 bits) value. 
        In this function we use bitwise << and >>, to remove the bits that isn't relevant to the suit, meaning that the bit sequence
        returned from this function is in the format: 000000XX.
        We assume (based on the way we initiate the cards) that bits 6-7 will be 0, and bits 0-5 can be anything.
        Parameters:
            uint8_t - The card original value, from which we want to extract what is the value in bits 0-1
        Returns:
            uint8_t - The value of bits 0-1, which contains the suit value
 */
uint8_t extractSuitBits(uint8_t);

/*   ---------------------------
    | Function: extractRankBits |
     ---------------------------
        This function recives the card value, return the rank bits (2-5) value. 
        In this function we use bitwise >>, to remove the bits that isn't relevant to the rank, meaning that the bit sequence
        we received is 00XXXXXX, and the sequence that will return from this function will be in the format 0000XXXX.
        We assume (based on the way we initiate the cards) that bits 6-7 will be 0, and bits 0-5 can be anything.
        Parameters:
            uint8_t - The card original value, from which we want to extract what is the value in bits 2-5
        Returns:
            uint8_t - The value of bits 2-5, which contains the ranlk value
 */
uint8_t extractRankBits(uint8_t);

/*   ------------------------------
    | Function: printCardsInFormat |
     ------------------------------
        $$$$$   Used in testing and debugging.  $$$$$
        Helper function that prints the cards in the list passed as argumernt in the format: <rank> of <suit>
 */
void printCardsInFormat(List *);

/*   -------------------
    | Function: toLower |
     -------------------
        Helper function that returns a string in lower case.
        Parameters:
            char * - The string we want to transform to lower case
        Returns:
            char * - The string in lower case
 */
char * toLower(char *);


#endif 