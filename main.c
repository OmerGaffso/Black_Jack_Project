#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>


void gameInit();
void printCash();
void betPhase();
int checkBet();

static unsigned int cash;
static unsigned int bet;

int main(void)
{
    cash = 1000;
    gameInit();
    return 0;
}

/*   --------------------
    | Function: gameInit |
     --------------------
        This function introduce the game to the player. 
        From this function, we call the functions to initiate everything we need for a solid game of black jack.
 */
void gameInit(){
    printf("Welcome to the Black Jack table!\nI'm Omer and I'll play against you.\n");
    printf("Bets are accepted in multiples of 10.\nIf your cash drops beneath 10$, it is Game Over for you.\n");
    printf("I hope you enjoy playing against me. Good Luck!\n");
    printf("---------------------------------------------------------------\n");
    putchar('\n');
    printCash();
    betPhase(); 
}

/*   ---------------------
    | Function: printCash |
     ---------------------
        Helper function to make printing cash and bet easier.
 */
void printCash(){
    printf("Your cash: %u$\tCurrent bet: %u$\n",cash, bet);
}

/*   --------------------
    | Function: betPhase |
     --------------------
        This function begins the actual game cycle. 
        It takes the user bet input until valid input is received. 
        If the bet value is invalid, prints to the user appropriate message.
 */
void betPhase() {
    int playerBet = 0;
    bool flag = true;
    int betCode;
    
    while(flag){ // runs until the user entered valid amount
        
        printf("Place your bet: \n");
        scanf("%d", &playerBet);
        betCode = checkBet(playerBet);
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
            printf("You cannot bet 0 if the bet pool is 0.\n\n");
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
    cash -= playerBet;
    bet += playerBet;
    printCash();
}

/*   --------------------
    | Function: checkBet |
     --------------------
    Checks if the user bet is valid.
    pBet- The player bet amount.
    returns:    if the player bet is valid, returns 0.
                if the player bet is invalid, returns validation error code:
                    1 = player cash is less than the bet amount.
                    2 = player tried to bet amount that isn't a mutiple of 10.
                    3 = player bet 0, when the betting pool is non-zero.
                    4 = player bet was negative number.
 */
int checkBet(int pBet) {
// Invalid bets:
    if(pBet > cash) 
        return 1;
    else if(pBet % 10 != 0)
        return 2;
    else if(bet == 0 && pBet == 0)
        return 3;
    else if(pBet < 0)
        return 4;
    else 
        return 0;
}