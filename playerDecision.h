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
#define ACE_VALUE 11                // Inital value of ace
#define ROYALTY_VALUE 10            // The value of royalty in a game of black jack

/*******************************************
*              Prototypes:                  *
 *******************************************/
/*   -------------------------------
    | Function: playerDecisionPhase |
     -------------------------------
        In this function, we prompt the user if he wishes to hit or stand.
        It runs in infinite loop, until: 
            the player has hand value of 21
            the player has hand value of over 21
            the player input "stand"
        Parameters:
            List * - Pointer to the player hand
            List * - Pointer to the deck
        Returns: an integer that indicates the outcome:
            21 (BLACK_JACK) - the player has black jack
            4 < x < 20 - the player stands, and returns it hand value; 
            -1 (BUST)- bust
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
            then the value of Ace will be calculated as 1 instead.
        Parameters:
            List * - The hand to calculate it's value
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