#include "data.h"

void printBits(uint8_t num) {

    for (uint8_t mask = 1<<7; mask != 0; mask >>= 1) {
        putchar( (num & mask)  ? '1' : '0');
    }
    puts("");
}

void welcomMessege(void){
    printf("Welcome to the Black Jack table!\nI'm Omer and I'll play against you.\n");
    printf("Bets are accepted in multiples of %d.\n",MIN_BET);
    printf("If your cash drops beneath %d$, it is Game Over for you.\n",MIN_BET);
    printf("I hope you enjoy playing against me. Good Luck!\n");
    printf("--------------------------------------------------------\n");
    putchar('\n'); 
}

char* getSuitName(Suit suit) {
    switch (suit) {
    case Diamonds:   return "Diamonds";
    case Clubs:      return "Clubs";
    case Hearts:     return "Hearts";
    case Spades:     return "Spades";
    
    default:
        printf("Unvalid suit!\n");
        return "";
    }
}

char* getRankName(Rank rank) {
    switch (rank) {
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

uint8_t extractSuitBits(uint8_t cardData) {
    /* 
    Moves the card bits 6 places left (to delete the rank bits) and than 6 places right 
    to leave only the suit bits to be translated
    */
    cardData <<= RANK_BITS;
    cardData >>= RANK_BITS;
    return cardData; 
}

uint8_t extractRankBits(uint8_t cardData) {
    /* 
    Moves the card bits 2 places right to delete the suit bits so the rank bits
    are on the least segnificant bits (0-3) location to be translated 
    */
    cardData >>= SUIT_BITS;
    return cardData;
}


void printCards(List* handP){
    Card *temp;
    const char *cardSuit, *cardRank;
    uint8_t cardData;

    temp = handP -> head;

    while (temp != NULL) {

        cardData = extractSuitBits(temp -> data);
        cardSuit = getSuitName(cardData);
         
        cardData = extractRankBits(temp -> data);
        cardRank = getRankName(cardData);
        printf("%s of %s\n", cardRank, cardSuit);
        temp = temp -> next;
    }
    puts("");
}


char * toLower(char *s) {
    for (char *p = s; *p; p++) 
        *p = tolower(*p);
    return s;
}


