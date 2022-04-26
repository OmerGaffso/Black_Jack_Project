#ifndef GAMEHANDLE_H
#define GAMEHANDLE_H

/*******************************************
*              Includes:                    *
 *******************************************/
#include "data.h"

/*******************************************
*              Defines:                    *
 *******************************************/
#define NO_CHECK_NEEDED 100             // pass the userEndGame check if no check needed

/*******************************************
*              Prototypes:                  *
 *******************************************/

/* HELPER FUNCTIONS THAT HANDLE THE GAME CONCLOSION */
void blackJack(unsigned int *, unsigned int *, unsigned int *, bool*);

void playerBust(unsigned int *, unsigned int *, unsigned int *, bool*);

void dealerWin(unsigned int *, unsigned int *, unsigned int *, bool*);

void dealerBust(unsigned int *, unsigned int *, unsigned int *, bool*);

void playerWon(unsigned int *, unsigned int *, unsigned int *, bool*);

void tie(unsigned int *, bool *);

/*   -----------------------
    | Function: userEndGame |
     -----------------------
        This function checks the player cash, and prompts the player if he/she wants to end the game (if cash is above 10). 
        The input should be yes to continue playing or no to end the game.
        (changes the play flag in main based on user input)
        Parameters:
            unsigned int - the player csah
            bool * - the keep playing flag to change
        Retrurns: 
            true - if the user input was "yes", meaning he wants to continue playing 
            false - if the user input was "no", meaning he wants to end the game or if the player cash is lower than 10.
 */
bool userEndGame(unsigned int, bool *);
#endif 