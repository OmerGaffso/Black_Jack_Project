#ifndef DRAWPHASE_H
#define DRAWPHASE_H

/*******************************************
*              Includes:                    *
 *******************************************/
#include "data.h"
#include "lists.h"
#include <time.h>
#include <string.h>

/*******************************************
*              Prototypes:                  *
 *******************************************/
/*   ---------------------
    | Function: drawPhase |
     ---------------------
        The main function for the third phase of the game. 
        From this function we will draw the initial hands of the player and dealer hands, and print their hands for the user. 
 */
void drawPhase(List*, List*, List*);

/*   --------------------------
    | Function: drawRandomCard |
     --------------------------
        This function receives a pointer to the deck and a pointer to either the player or dealer hands.
        It uses the random helper function to generate number between 1-52. 
        It draws the Card from the Deck that is positioned in the number place, and adds it to the hand of the player/dealer.
 */
void drawRandomCard(List*, List*);

/*   ---------------------
    | Function: printHand |
     ---------------------
        This function prints a hand.
        Prints the hand in the format:  player: <rank> of <suit>,\t <rank> of <suit>
                                        or
                                        dealer: <rank> of <suit>,\t ???? ????
        It receives as parameters the hand head pointer and a char - 'p' for player and 'd' for dealer.
 */
void printHand(List*, char);

/*   --------------------------
    | Function: generateRandom |
     --------------------------
        This function generate a random number between 1-[deck_length]. 
        Receive the length of the deck as argument, to generate number between 1 and deck length. 
 */
int generateRandom(int);

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



#endif