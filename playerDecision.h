#ifndef PLAYERDECISION_H
#define PLAYERDECISION_H

/*******************************************
*              Includes:                    *
 *******************************************/
#include "data.h"
#include "lists.h"

/*******************************************
*              Prototypes:                  *
 *******************************************/
/*   -------------------------------
    | Function: playerDecisionPhase |
     -------------------------------
        The main function of the 4th game phase. 
        From this function, we will call all other necessary function.
        Receives the player hand to use in other functions.
 */
void playerDecisionPhase(List *);

/*   ------------------------------
    | Function: calculateHandValue |
     ------------------------------
        This function receives a hand of cards, and calculate it's value.
        Calculate the hand value based on the following rules:
            King, Queen and Jack values are 10.
            2-10 will be calculated as face value.
            If the hand contains at least one Ace, it's initial value is 11. However, if the total value of the hand is over 21 (including the Ace value),
            then the value of Ace will be calculated as the value 1 instead.
 */
int calculateHandValue(List *);

#endif