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
#define DECKSIZE 52                 // number of cards in the deck
#define SUITS_NUMBER 4              // number of suits in a deck of cards
#define CARDS_IN_SUIT 13            // number of cards per suit
#define HAND_INIT_SIZE 2            // number of card per hand in the beginning of a black jack roun
#define MAX_NAME_LEN 10             // maximum size of rank/suit length (used for initiating strings throughout the game)
// #define SUIT_MASK 0x03
// #define RANK_MASK 0x3C
#define SUIT_BITS 2                 // number of bits that represent the suit in a uint8_t variable
#define RANK_BITS 6                 // number of bits that represent the rank in a uint8_t variable (including bits 6-7) 
#define BLACK_JACK 21               // value that represents Black Jack
#define BUST -1                     // value that represent the situation of player/dealer has hand value larger than 21
#define BLACK_JACK_MULTIPLIER 2.5   // multiplier of black jack
#define WIN_BET_MULTIPLIER 2        // multiplier of regular win 
#define MIN_BET 10                  // minimum cash to make a bet


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

/*   ------------------------------
    | Function: printCardsInFormat |
     ------------------------------
        Helper function that prints the cards in the list passed as argumernt in the format: <rank> of <suit>
 */
void printCardsInFormat(List *);

/*   ---------------------
    | Function: blackJack |
     ---------------------
        Helper function that prints "Black Jack!\n"
 */
void blackJack();

/*   -------------------
    | Function: toLower |
     -------------------
        Helper function that receives a string as a parameter and returns the string in lower case.
 */
char * toLower(char *);

/*   -----------------------
    | Function: userEndGame |
     -----------------------
        This function prompts the player if he/she wants to end the game. The input should be yes to continue playing or no to end the game.
        (changes the play flag in main based on user input)
        Retrurns: 
            true - if the user input was "yes", meaning he wants to continue playing 
            false - if the user input was "no", meaning he wants to end the game
 */
bool userEndGame();
#endif 