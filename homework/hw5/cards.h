#ifndef CARDS_H
#define CARDS_H

/* To represent a playing card, use
 * an 8 bit variable, like a 'char'  // I used int instead
 *
 * The value of the card is stored in the 
 * bottom 4 bits
 *
 * The suite of the card is stored in the next 2 
 * bits
 */

// Bitmasks
#define VALUE_MASK 0x0F // card & VALUE_MASK = value of a card
#define SUITE_MASK 0x40 // card & SUITE_MASK = suite of a card

// Card Values
#define ACE   0x01
#define TWO   0x02
#define THREE 0x03
#define FOUR  0x04
#define FIVE  0x05
#define SIX   0x06
#define SEVEN 0x07
#define EIGHT 0x08
#define NINE  0x09
#define TEN   0x0a
#define JACK  0x0b
#define QUEEN 0x0c
#define KING  0x0d

// Card Suites
#define CLUBS    0x00
#define HEARTS   0x10
#define DIAMONDS 0x20
#define SPADES   0x30

// Sets whether a card has been dealt
#define DEALT 0x80

/* 
 * the lowest value card representation = ACE of CLUBS   = 0x01.
 * the higest value card representation = KING of SPADES = 0x3d.
 */


/*=============================*/
/*=== Function Declarations ===*/
/*=============================*/

// prints a card's value and suite
void print_card( int card);
// {
//  	PRECONDITIONS  : none
//  	POSTCONDITIONS : none
//  	RETURN         : none
// }


// finds the value of a card
int card_value( int card );
// {
//  	PRECONDITIONS  : none
//  	POSTCONDITIONS : none
//  	RETURN         : value of card
// }


// checks if card is an ace
int is_ace( int card );
// {
//  	PRECONDITIONS  : none
//  	POSTCONDITIONS : none
//  	RETURN         : 1 is card is an ace, 0 if not
// }


// Checks if the card entered has been dealt
int is_dealt( int card );
// {
//  	PRECONDITIONS  : none
//  	POSTCONDITIONS : none
//  	RETURN         : 1 if card has been dealt, 0 if not
// }


#endif