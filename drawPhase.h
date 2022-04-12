#ifndef DRAWPHASE_H
#define DRAWPHASE_H

/*******************************************
*              Includes:                    *
 *******************************************/
#include "data.h"
#include "lists.h"
#include <time.h>

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

/*   -----------------
    | Function: ranks |
     -----------------
        This function receives a uint8_t, and based on bits 2-5 translate the value into card rank.
        Returns a string with single digit (2-9) if the card value is a digit, or a string containing the rank name (King, Queen, Prince or Ace)  
 */
char [] ranks(uint8_t);

/*   -----------------
    | Function: suits |
     -----------------
        This function receives a uint8_t, and based on bits 0-1 translate the value into card suit.
        returns a string containing the suit of the card (Diamonds, Clubs, Hearts or Spades).
 */
char [] suits(uint8_t);




#endif