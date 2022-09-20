#ifndef GAMEHANDLE_H
#define GAMEHANDLE_H

/*******************************************
*            File Description:              *
 *******************************************/
/*
    This file contains the functions that determines whether the game is ended 
    or not based on player decision or the player remining cash. 
*/

/*******************************************
*              Includes:                    *
 *******************************************/
#include "data.h"

/*******************************************
*              Prototypes:                  *
 *******************************************/

/*  HELPER FUNCTIONS THAT HANDLE THE GAME CONCLOSION 
        Prints the situation based on player hand value (blackJack or bust) or based on 
        the comparison between the hand values of the player and dealer.
        Based on the situation, adds the pot to the player (multiplied by the cooresponding multiplier),
        or reset the pot and playerBet to 0.
        In case of a tie- resets only the playerBet variable to 0.
    Parameters:
        unsigned int * - pointer to the player cash
        unsigned int * - pointer to bet pot
        unsigned int * - pointer to the player bet value

    **** The tie function receives only the playerBet variable and sets it to 0. ***
*/
void blackJack(unsigned int *cash,unsigned int *pot, unsigned int *playerBet);

void playerBust(unsigned int *cash,unsigned int *pot, unsigned int *playerBet);

void dealerWin(unsigned int *cash,unsigned int *pot, unsigned int *playerBet);

void dealerBust(unsigned int *cash,unsigned int *pot, unsigned int *playerBet);

void playerWon(unsigned int *cash,unsigned int *pot, unsigned int *playerBet);

void tie(unsigned int *playerBet);

/*   -----------------------
    | Function: userEndGame |
     -----------------------
        This function checks the end game condition.
        First, it checks the player cash. If the player cash is below 10$,
        prints game over and change the game flag to false (ending the game loop).
        After that, it prompts the player if he/she wants to continue playing the game. 
        The input should be yes to continue playing or no to end the game.
        (changes the play flag in main based on user input)
        Parameters:
            unsigned int - the player csah
            unsigned int - the pot
        Retrurns: 
            true - if the user input was "yes", meaning he wants to continue playing 
            false - if the user input was "no", meaning he wants to end the game or if
                    the player cash is lower than 10 and the pot is 0.
 */
bool userEndGame(unsigned int cash, unsigned int pot);
#endif 