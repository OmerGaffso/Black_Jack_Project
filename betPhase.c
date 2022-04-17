#include "betPhase.h"

// Global variables:
// extern unsigned int *cash;
// extern unsigned int *pot;

void betPhase(unsigned int *cash, unsigned int *pot) {
    // printCash();
    // printf("in betPhase\n"); // DELETE
    int playerBet = 0;
    bool flag = true;
    int betCode;
    
    while(flag){ // runs until the user entered valid amount
        
        printf("Place your bet: \n");
        scanf("%d", &playerBet);
        betCode = checkBet(playerBet, cash, pot);
        switch (betCode)
        {
        // Invalid bets:
        case 1:
            printf("You cannot bet larger amount than your cash.\n\n");
            break;
        
        case 2:
            printf("The bet amount can be only a multiple of 10.\n\n");
            break;
        
        case 3:
            printf("You cannot bet 0 if the pot is 0.\n\n");
            break;
        
        case 4:
            printf("You cannot bet negative number.\n\n");
            break;
        // Valid bets: 
        case 0:
            flag = false;
            break;
        default:
            printf("Invalid Bet.\n\n");
            break;
        }
    }
    *cash -= playerBet;
    *pot += playerBet;
    // printCash(cash, pot); // TEST TO SEE EVERYTHING WORKS PROPERLY
}


int checkBet(int pBet, unsigned int *cash, unsigned int *pot) {
    // Invalid bets:
    if(pBet > *cash) 
        return 1;
    else if(pBet % 10 != 0)
        return 2;
    else if(*pot == 0 && pBet == 0)
        return 3;
    else if(pBet < 0)
        return 4;
    // Valid Bet
    else 
        return 0;
}