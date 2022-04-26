#ifndef DEALERPHASE_H
#define DEALERPHASE_H

/*******************************************
*              Includes:                    *
 *******************************************/

#include "data.h"
#include "lists.h"
#include "playerDecision.h"

/****************************************
*              Defines:                  *
 ****************************************/

#define MIN_DEALER_HAND_VAL 17          // The dealer will stop drawing if he has 17 or more
#define DEALER_WIN 1                    // Status code
#define DEALER_LOST 0                   // Status code
#define TIE 2                           // tie status code

/*******************************************
*              Prototypes:                  *
 *******************************************/

/*   ---------------------------
    | Function: dealerDrawPhase |
     ---------------------------
        This function runs the dealer algorithm, and determines which player wins.
        The dealer will draw cards until his hand value is greater or equal to 17, then he stops drawing cards.
        Parameters:
            List * - Dealers hand list
            List * - Deck list
            int - The player hand value
        Returns: integer that indicates the situation:
            return 1 (DEALER_WIN)- dealer hand value is greater than the player hand value (and lesser or equal to 21)
            return 0 (DEALER_LOST- dealer hand value is greater or equal to 17 (dealer stop drawing cards), but lesser than the player hand value
            retrun -1 (BUST)- dealer draw cards and his hand value is greater than 21
            return handValue - dealer draw till his hand value is greater than 17 and lesser than 21, and his hand value is equal to the player hand value
 */
int dealerDrawPhase(List *, List *, int);

#endif