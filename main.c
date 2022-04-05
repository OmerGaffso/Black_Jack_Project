#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

#define DECKSIZE 52
#define SUITS_NUMBER 4
#define CARDS_IN_SUIT 13

/* TODO: move the structs to the appropriate file later in project */
 
typedef struct{
    uint8_t data;
    struct Card* next;
}Card;

// Helper Functions 
void print_bits_u8(uint8_t num);
void printDeck();

// Deck Operations
void initDeck();
void addNewCard(uint8_t);


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
Card *d_head = NULL; // pointer to the start of the deck
Card *d_tail = NULL; // pointer to the end of the deck
Card *playerHand = NULL; 
Card *dealerHand = NULL;

int main(void)
{
    gameInit();
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

    welcomMessege();
    while(!endGameFlag){
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

/*   ---------------------
    | Function: printCash |
     ---------------------
        Helper function to make printing cash and bet easier.
 */
void printCash(){
    printf("Your cash: %u$\tCurrent bet: %u$\n",cash, pot);
}

/*   ---------------------
    | Function: initDeck |
     ---------------------
        This function create the cards unique bit sequence.
        It will create 52 cards, 13 cards for each suit- spades, diamonds, hearts and clubs.
        Bits 0-1 will indicate the suit of the card-    00 = spades
                                                        01 = hearts
                                                        10 = clubs
                                                        11 = diamonds
        bits 2-5 will indicate the rank of the card-    0001 = Ace
                                                        ...
                                                        ...
                                                        ...
                                                        1101 = King
        bits 6-7 will indicate nothing about the card.
        for example: 01110101 = King of hearts.
        At the end of the function, we will have a full deck.  
 */
void initDeck() {
    uint8_t value = 0x00;
    uint8_t mask = 0x00;
    size_t n = 2;

    for (size_t i = 0; i < DECKSIZE; i++){ 
        
        for (size_t j = 0; j < CARDS_IN_SUIT; j++) {
            mask |= 1 << (n + j);
            value |= mask;
            addNewCard(value);
        }
    }
}

/*   ---------------------
    | Function: addNewCard |
     ---------------------
        This function adds the cards to the end of the deck.
 */
void addNewCard(uint8_t val) {
    Card *card = malloc(sizeof(Card));
    card -> data = val;
    card -> next = NULL;

    if (d_head == NULL){ // Deck is empty, adding first card
        d_head == card;
        d_tail == card;
    }
    else { // Deck is not empty, adding card to the end of the Deck.
        Card *temp = d_head;

        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = card;
        d_tail = card;
    } 
}

/*   ---------------------
    | Function: print_bits_u8 |
     ---------------------
        Helper function. receives uint8_t number and prints it's bits.
 */
void print_bits_u8(uint8_t num) {
    int x = 0;

    for (uint8_t mask = 1<<7; mask != 0; mask >>= 1) {
        putchar( (num & mask)  ? '1' : '0');
        if (x == 7) {
            putchar(' ');
            x = 0;
        }
        else {
            x++;
        }
    }
    puts("");
}

void printDeck() {
    Card *temp = d_head;
    while(temp != NULL){
        printf("%u\n", temp -> data);
    }
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