#ifndef DRAWPHASE_H
#define DRAWPHASE_H

/*******************************************
*            File Description:              *
 *******************************************/
/*
    This file contains the functions for drawing the initial cards from the deck,
    the print functions of the card to the user, and the random number generator function.
*/

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
/*   ----------------------------
    | Function: initialDrawPhase |
     ----------------------------
        The main function for the third phase of the game. 
        From this function we will draw the initial hands of the player and dealer hands, 
        and print their hands for the user. 
        Parameters:
            List * - Pointer to the deck
            List * - Pointer to the players hand
            List * - Pointer to the dealer hand
 */
void initialDrawPhase(List *deckP, List *playerP, List *dealerP);

/*   --------------------------
    | Function: drawRandomCard |
     --------------------------
        This function calls generateRandom to get a random number, "draws" the card at the 
        random index from the deck, and adds it to the given hand.
        Parameters:
            List * - Pointer to the deck
            List * - Pointer to the hand
 */
void drawRandomCard(List *deckP, List *handP);

/*   ---------------------
    | Function: printHand |
     ---------------------
        This function prints a hand.
        Prints the hand in the format:  player: <rank> of <suit>,\t <rank> of <suit>
                                        or
                                        dealer: <rank> of <suit>,\t ???? ????
        Parameters:
            List * - Pointer to the list that will be printed
            char - 'p' or 'd', that indicates if the hand is the player's or the dealer's
 */
void printHand(List* handP, char handCode);

/*   --------------------------
    | Function: generateRandom |
     --------------------------
        This function generate a random number between 0- [deck length - 1]. 
        Parameters:
            int - The length of the deck list
        Returns: 
            int - a random number between 0 and the deck length - 1
 */
int generateRandom(int deckSize);

#endif