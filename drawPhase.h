#ifndef DRAWPHASE_H
#define DRAWPHASE_H

/*******************************************
*              Includes:                    *
 *******************************************/
#include "data.h"
#include "lists.h"

/*******************************************
*              Prototypes:                  *
 *******************************************/
/*   ---------------------
    | Function: drawPhase |
     ---------------------
        The main function for the third phase of the game. 
        From this function we will draw the initial hands of the player and dealer hands, and print their hands for the user. 
 */
void drawPhase(Card*, Card*, Card*);

/*   --------------------------
    | Function: drawRandomCard |
     --------------------------
        This function receives a pointer to the deck and a pointer to either the player or dealer hands.
        It uses the random helper function to generate number between 1-52. 
        It draws the Card that is positioned in the number place, and adds it to the hand of the player/dealer.
 */
void drawRandomCard(Card*, Card*);

/*   ------------------
    | Function: random |
     ------------------
        This function generate a random number between 1-52. 
 */
int random();




#endif