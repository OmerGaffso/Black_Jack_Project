#include "data.h"
#include "lists.h"

// Phase 1
void gameInit(); 
void welcomMessege();
void printCash();

// Phase 2
void betPhase();
int checkBet();

// Global Variables
static unsigned int cash;
static unsigned int pot;
static bool endGameFlag;

int main(void)
{
    gameInit();
    //TEST
    // Card *d_head = NULL; // pointer to the start of the deck
    // initDeck(d_head);


    return 0;
}

/*   --------------------
    | Function: gameInit |
     --------------------
        This function is phase 1 of the game. 
        From this function, we call the functions to introduce the game to the user, and initiate everything we need for a solid game of black jack.
        We will enter the game endless loop in this function, until we get input from user that he wants to end the game.
 */
void gameInit() {
    cash = 1000;
    pot = 0;
    endGameFlag = false;
    Card *d_head = NULL; // pointer to the start of the deck
    Card *playerHand = NULL; 
    Card *dealerHand = NULL;

    welcomMessege();
    while(!endGameFlag){ // Game Loop - Ends only when player wants to quit.
        initDeck(d_head);
        printCash();

        betPhase();
    }
}

/*   --------------------
    | Function: welcomMessege |
     --------------------
        This function introduce the game to the player. 
        From this function, we call the functions to initiate everything we need for a solid game of black jack.
 */
void welcomMessege(){
    printf("Welcome to the Black Jack table!\nI'm Omer and I'll play against you.\n");
    printf("Bets are accepted in multiples of 10.\nIf your cash drops beneath 10$, it is Game Over for you.\n");
    printf("I hope you enjoy playing against me. Good Luck!\n");
    printf("---------------------------------------------------------------\n");
    putchar('\n'); 
}


// MOVE TO DATA.H
/*   ---------------------
    | Function: printCash |
     ---------------------
        Helper function to make printing cash and bet easier.
 */
void printCash(){
    printf("Your cash: %u$\tCurrent bet: %u$\n",cash, pot);
}


/*   ---------------------
    | Function: print_bits_u8 |
     ---------------------
        Helper function. receives uint8_t number and prints it's bits.
 */
// void print_bits_u8(uint8_t num) {
//     int x = 0;

//     for (uint8_t mask = 1<<7; mask != 0; mask >>= 1) {
//         putchar( (num & mask)  ? '1' : '0');
//         if (x == 7) {
//             putchar(' ');
//             x = 0;
//         }
//         else {
//             x++;
//         }
//     }
//     puts("");
// }

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
    cash -= playerBet;
    pot += playerBet;
    printCash(); // TEST TO SEE EVERYTHING WORKS PROPERLY
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
                    3 = player bet 0, when the pot is non-zero.
                    4 = player bet was negative number.
 */
int checkBet(int pBet) {
    // Invalid bets:
    if(pBet > cash) 
        return 1;
    else if(pBet % 10 != 0)
        return 2;
    else if(pot == 0 && pBet == 0)
        return 3;
    else if(pBet < 0)
        return 4;
    // Valid Bet
    else 
        return 0;
}