#ifndef PLAYERSPHASE_H
#define PLAYERSPHASE_H

/*******************************************
*            File Description:              *
 *******************************************/
/*
    This file contains the functions that are used in the player phase.  
    These include the hit/stand decision, the hand value calculation, 
    and the dealer logic.
*/

/*******************************************
*              Includes:                    *
 *******************************************/

#include "data.h"
#include "lists.h"
#include "drawPhase.h"

/****************************************
*              Definitions:              *
 ****************************************/
#define ACE_VALUE 11                        // Inital value of ace
#define ROYALTY_VALUE 10                    // The value of royalty in a game of black jack
#define ACE_BONUS 10                        // The value of ace can be 1 or 11
#define MIN_DEALER_HAND_VAL 17              // The dealer will stop drawing if he has 17 or more
#define DEALER_RESULT_WIN 1                 // Status code
#define DEALER_RESULT_LOST 0                // Status code
#define DEALER_RESULT_TIE 2                 // tie status code
#define DEALER_RESULT_BUST -1               // bust status code

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
int playerDecisionPhase(List *hand, List *deck);

/*   ------------------------------
    | Function: calculateHandValue |
     ------------------------------
        This function receives a hand of cards, and calculate it's value.
        Calculate the hand value based on the following rules:
            King, Queen and Jack values are 10.
            2-10 will be calculated as face value.
            If the hand contains at least one Ace, it's initial value is 11. 
            However, if the total value of the hand is over 21 (including the Ace value),
            then the value of Ace will be calculated as 1 instead.
        Parameters:
            List * - The hand to calculate it's value
        Returns:   
            The hand value (4-21)
            0 if the hand value is over 21
 */
int calculateHandValue(List *hand);

/*   ------------------------------
    | Function: playerDecisionPhase |
     ------------------------------
     Helper function that prints the hand value of the player or the dealer based on isPlayer flag.
     If the hand value is a bust or blackjack, does not print the value.
     Parameters:
        int - the hand value calculated in calculateHandValue function.
        bool - if true, the hand value is the player's. if false the hand value is the dealer's.

*/
void printHandValue(int handVal, bool isPlayer);

/*   ---------------------------
    | Function: dealerDrawPhase |
     ---------------------------
        This function runs the dealer algorithm, and determines which player wins.
        The dealer will draw cards until his hand value is greater or equal to 17, 
        then he stops drawing cards.
        Parameters:
            List * - Dealers hand list
            List * - Deck list
            int - The player hand value
        Returns: integer that indicates the situation:
            return 1 (DEALER_STATUS_WIN)-   dealer hand value is greater than the player hand value 
                                            (and less or equal to 21)
            return 0 (DEALER_STATUS_LOST-   dealer hand value is greater or equal to 17 (dealer stop drawing
                                            cards), but less than the player hand value
            retrun -1 (DEALER_STATUS_BUST)- dealer draw cards and his hand value is greater than 21
            return 2 (DEALER_STATUS_TIE)-   dealer draw till his hand value is greater than 17 and less 
                                            than 21, and his hand value is equal to the player hand value
 */
int dealerDrawPhase(List *dealerHand, List *deck, int dealerHandVal, int playerHandVal);

#endif