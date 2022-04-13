#include "data.h"

void printBits(uint8_t num) {
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

void welcomMessege(){
    printf("Welcome to the Black Jack table!\nI'm Omer and I'll play against you.\n");
    printf("Bets are accepted in multiples of 10.\nIf your cash drops beneath 10$, it is Game Over for you.\n");
    printf("I hope you enjoy playing against me. Good Luck!\n");
    printf("---------------------------------------------------------------\n");
    putchar('\n'); 
}

void printCash(unsigned int *cash, unsigned int *pot){
    printf("Your cash: %u$\tCurrent bet: %u$\n",*cash, *pot);
}

const char* getSuitName(enum suits Suit) {
    switch (Suit) {
    case Diamonds:   return "Diamonds";
    case Clubs:      return "Clubs";
    case Hearts:     return "Hearts";
    case Spades:     return "Spades";
    
    default:
        printf("Unvalid suit!\n");
        return "";
    }
}

const char* getRankName(enum ranks Rank) {
    switch (Rank) {
    case Ace:    return "Ace";
    case Two:    return "2";
    case Three:  return "3";
    case Four:   return "4";
    case Five:   return "5";
    case Six:    return "6";
    case Seven:  return "7";
    case Eight:  return "8";
    case Nine:   return "9";
    case Ten:    return "10";
    case Jack:   return "Jack";
    case Queen:  return "Queen";
    case King:   return "King";

    default:
        printf("Invalid Card Rank!\n");
        return "";
    }
}