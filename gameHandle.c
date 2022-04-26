#include "gameHandle.h"

void blackJack(unsigned int *cash,unsigned int *pot, unsigned int *playerBet, bool *play) {
    printf("Black Jack!\n");
    *pot *= BLACK_JACK_MULTIPLIER;
    *cash += *pot;
    *playerBet = 0;
    *pot = 0;

    *play = userEndGame(NO_CHECK_NEEDED, play); // prompts the user if he/she wishes to continue playing
}

void playerBust(unsigned int *cash, unsigned int *pot, unsigned int *playerBet, bool *play) {
    printf("Bust!\n");
    *pot = 0;
    *playerBet = 0;

    *play = userEndGame(*cash, play); // prompts the user if he/she wishes to continue playing
}

void dealerWin(unsigned int *cash, unsigned int *pot, unsigned int *playerBet, bool *play) {
    printf("Dealer Wins!\n");
    *pot = 0;
    *playerBet = 0;

    *play = userEndGame(*cash, play); // prompts the user if he/she wishes to continue playing  
}

void dealerBust(unsigned int *cash, unsigned int *pot, unsigned int *playerBet, bool*play) {
    printf("Dealer Bust!\n");
    *cash += *pot * WIN_BET_MULTIPLIER;
    *pot = 0;
    *playerBet = 0;

    *play = userEndGame(NO_CHECK_NEEDED, play); // prompts the user if he/she wishes to continue playing
}

void playerWon(unsigned int *cash,unsigned int *pot, unsigned int *playerBet, bool *play) {
    printf("You Win!\n");
    *cash += *pot * WIN_BET_MULTIPLIER;
    *pot = 0;
    *playerBet = 0;
    
    *play = userEndGame(NO_CHECK_NEEDED, play); // prompts the user if he/she wishes to continue playing
}

void tie(unsigned int *playerBet, bool *play) {
    printf("Tie!\n");
    *playerBet = 0;
        
    *play = userEndGame(NO_CHECK_NEEDED, play); // prompts the user if he/she wishes to continue playing
}

bool userEndGame(unsigned int cash, bool *play) {
    char s[MAX_NAME_LEN];

    if (cash < MIN_BET) {
        printf("Out of cash to make a bet.\nGAME OVER!\n");
        play = false;
    }

    while(true) {
        printf("Do you wish to play again? (yes/no)\n");
        scanf(" %s", &s[0]);
        
        toLower(s);
        if (strcmp(s, "yes") == 0)
            return true;
        else if (strcmp(s, "no") == 0)
            return false;
        else printf("Invalid input.\n");
    }
}