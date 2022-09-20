#include "gameHandle.h"

void blackJack(unsigned int *cash,unsigned int *pot, unsigned int *playerBet) {
    printf("Black Jack!\n");
    *pot *= BLACK_JACK_MULTIPLIER;
    *cash += *pot;
    *playerBet = 0;
    *pot = 0;
}

void playerBust(unsigned int *cash, unsigned int *pot, unsigned int *playerBet) {
    printf("Bust!\n");
    *pot = 0;
    *playerBet = 0;
}

void dealerWin(unsigned int *cash, unsigned int *pot, unsigned int *playerBet) {
    printf("Dealer Wins!\n");
    *pot = 0;
    *playerBet = 0;
}

void dealerBust(unsigned int *cash, unsigned int *pot, unsigned int *playerBet) {
    printf("Dealer Bust!\n");
    *cash += *pot * WIN_BET_MULTIPLIER;
    *pot = 0;
    *playerBet = 0;
}

void playerWon(unsigned int *cash,unsigned int *pot, unsigned int *playerBet) {
    printf("You Win!\n");
    *cash += *pot * WIN_BET_MULTIPLIER;
    *pot = 0;
    *playerBet = 0;
}

void tie(unsigned int *playerBet) {
    printf("Tie!\n");
    *playerBet = 0;
}

bool userEndGame(unsigned int cash, unsigned int pot) {
    char s[MAX_NAME_LEN];

    /*
        if the player cash is less than the minimum bet, it's a game over - unless
        the previous game ended in a tie. in that case, the pot stays the same, 
        and the player can bet 0, so the player has a chance to win the next round and keep on playing.
    */
    if (cash < MIN_BET && pot == 0){
            printf("Out of cash.\nGAME OVER!\n");
            return false;
    }

    while(true) {
        printf("Do you wish to play again? (yes/no)\n");
        scanf(" %s", &s[0]);
        
        toLower(s);
        if (strcmp(s, "yes") == 0)
            return true;
        else if (strcmp(s, "no") == 0) {
            printf("You chose to end the game.\nHope you enjoyed playing!\n");
            return false;
        }
        else printf("Invalid input.\n");
    }
}