#ifndef BETPHASE_H
#define BETPHASE_H

/*******************************************
*              Includes:                    *
 *******************************************/
#include "data.h"


/*******************************************
*              Prototypes:                  *
 *******************************************/
/*   --------------------
    | Function: betPhase |
     --------------------
        This function begins the actual game cycle. 
        It takes the user bet input until valid input is received. 
        If the bet value is invalid, prints to the user appropriate message.
 */
void betPhase(unsigned int *, unsigned int *);

/*   --------------------
    | Function: checkBet |
     --------------------
    Checks if the user bet is valid.
    pBet- The player bet amount.
    returns:    if the player bet is valid, returns 0.
                if the player bet is invalid, returns validation error code:
                    1 = player cash is less than the bet amount.
                    2 = player tried to bet amount that isn't a mutiple of 10.
                    3 = player bet 0, when the pot is non-zero.
                    4 = player bet was negative number.
 */
int checkBet(int, unsigned int *, unsigned int *);

#endif