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

/*  HELPER FUNCTIONS THAT HANDLE THE GAME CONCLOSION 
        Prints the situation based on player hand value (blackJack or bust) or based on the comparison between the hand values of the player and dealer.
        Based on the situation, adds the pot to the player (multiplied by the cooresponding multiplier), or reset the pot and playerBet to 0.
        In case of a tie- resets only the playerBet variable to 0.
    Parameters:
        unsigned int * - pointer to the player cash
        unsigned int * - pointer to bet pot
        unsigned int * - pointer to the player bet value
        bool * - pointer to the play flag, which indicates if the player wants to play

*/
void blackJack(unsigned int *, unsigned int *, unsigned int *, bool*);

void playerBust(unsigned int *, unsigned int *, unsigned int *, bool*);

void dealerWin(unsigned int *, unsigned int *, unsigned int *, bool*);

void dealerBust(unsigned int *, unsigned int *, unsigned int *, bool*);

void playerWon(unsigned int *, unsigned int *, unsigned int *, bool*);

void tie(unsigned int *, bool *);

/*   -----------------------
    | Function: userEndGame |
     -----------------------
        This function checks the end game condition.
        First, it checks the player cash. If the player cash is below 10$, prints game over and change the game flag to false (ending the game loop).
        After that, it prompts the player if he/she wants to continue playing the game. 
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