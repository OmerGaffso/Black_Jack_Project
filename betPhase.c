#include "betPhase.h"

void betPhase(unsigned int *cash, unsigned int *pot) {
    int playerBet = 0;
    bool invalidInput = true;
    int betCode;
    
    while(invalidInput){ // runs until the user entered valid amount
        
        printf("Place your bet: \n");
        scanf(" %d", &playerBet);
        getchar(); // flush buffered '\n'
        betCode = checkBet(playerBet, *cash, *pot);
        switch (betCode)
        {
        // Invalid bets:
        case BETERROR_NEGATIVE:
            printf("You cannot bet negative number.\n\n");
            break;
        
        case BETERROR_NOT_IN_TENS:
            printf("The bet amount can be only a multiple of 10.\n\n");
            break;
        
        case BETERROR_ZERO_BET:
            printf("You cannot bet 0 if the pot is 0.\n\n");
            break;
        
        case BETERROR_NOT_ENOUGH_CASH:
            printf("You cannot bet larger amount than your cash.\n\n");            
            break;
        // Valid bet: 
        case VALID_BET:
            invalidInput = false;
            break;
        default:
            printf("Invalid Bet.\n\n");
            break;
        }
    }
    *cash -= playerBet;
    *pot += playerBet;
}


int checkBet(int pBet, int cash, int pot) {
    // Invalid bets:
    if(pBet < 0) 
        return BETERROR_NEGATIVE;
    else if(pBet % 10 != 0)
        return BETERROR_NOT_IN_TENS;
    else if(pot == 0 && pBet == 0)
        return BETERROR_ZERO_BET;
    else if(pBet > cash)
        return BETERROR_NOT_ENOUGH_CASH;
    // Valid Bet
    else 
        return VALID_BET;
}