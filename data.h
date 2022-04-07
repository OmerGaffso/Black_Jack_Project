#ifndef DATA_H
#define DATA_H

/*******************************************
*              Includes:                    *
 *******************************************/
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h> 
/*******************************************
*              Defines:                     *
 *******************************************/
#define DECKSIZE 52
#define SUITS_NUMBER 4
#define CARDS_IN_SUIT 13

typedef struct Card{
    uint8_t data;
    struct Card* next;
}Card;

/*******************************************
*              Prototypes:                  *
 *******************************************/
// These are helper functions, used mainly for general purposes or testing.
void print_bits_u8(uint8_t num);


#endif 