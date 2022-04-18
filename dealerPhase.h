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

#define MIN_DEALER_HAND_VAL 17 

/*******************************************
*              Prototypes:                  *
 *******************************************/

/*   ---------------------------
    | Function: dealerDrawPhase |
     ---------------------------
        The main function for the dealer player. The dealer follows the following algorithm:
            Calculate the value of delaers hand. If it's greater than the value of the players hand, the dealer wins.
            Otherwise, the dealer will draw cards until one of the following occurs:
                1. The dealer hand value is greater than the players hand value.
                2. The dealer hand value reached 17 or more.
                3. The dealer hand value is over 21 - prints dealer bust and adds bet * 2 to player cash.
                4. The dealer hand value is over 17 and below 21, and is eaqual to the player hand value. In this case, the cards will be reset, but the bet will remain as is.
        Parameters:
            List * - Dealers hand list
            List * - Deck list
            int - The player hand value
        Returns: integer that indicates the situation:
            return 1 - indicates situation 1. (dealer won)
            return 0 - indicates dealer lost (draw up until dealer hand value > 17, but dealer hand value < player hand value).
            retrun -1 - indicates situation 3. (dealer bust)
            return handValue - indicates situation 4. (tie)
 */
int dealerDrawPhase(List *, List *, int);

#endif