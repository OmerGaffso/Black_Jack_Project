#ifndef PLAYERDECISION_H
#define PLAYERDECISION_H

/*******************************************
*              Includes:                    *
 *******************************************/
#include "data.h"
#include "lists.h"
#include "drawPhase.h"

/*******************************************
*              Defines:                    *
 *******************************************/
#define ACE_VALUE 11
#define ROYALTY_VALUE 10

/*******************************************
*              Prototypes:                  *
 *******************************************/
/*   -------------------------------
    | Function: playerDecisionPhase |
     -------------------------------
        The main function of the 4th game phase. 
        From this function, we will call all other necessary function.
        Receives the player hand to use in other functions.
        Returns an integer that indicates the outcome:
            21 - the player has black jack
            4 < x < 20 - the player stands, and returns it hand value; 
            -1 - bust
 */
int playerDecisionPhase(List *, List *);

/*   ------------------------------
    | Function: calculateHandValue |
     ------------------------------
        This function receives a hand of cards, and calculate it's value.
        Calculate the hand value based on the following rules:
            King, Queen and Jack values are 10.
            2-10 will be calculated as face value.
            If the hand contains at least one Ace, it's initial value is 11. However, if the total value of the hand is over 21 (including the Ace value),
            then the value of Ace will be calculated as the value 1 instead.
        Returns:   
            The hand value (4-21)
            0 if the hand value is over 21
 */
int calculateHandValue(List *);

/*   ---------------------
    | Function: isRoyalty |
     ---------------------
        This function receives a string and checks if the string is royalty name.
        Parameters:
            char * - the string to check.
        Returns:
            true if the string is royalty (King, Queen, Jack).
            false if the string isn't royalty.
 */
bool isRoyalty(char *);

#endif