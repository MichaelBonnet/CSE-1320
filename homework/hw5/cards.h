/* Name of Last Editor : Michael Bonnet
 * Date of Last Edit   : 03/29/2019
 * Time of Last Edit   : 11:49 CDT (GMT-6)
 */

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

/*==================================*/
/*=== Macro/Constant Definitions ===*/
/*==================================*/

// Bitmasks
#define VALUE_MASK 0x0F // card & VALUE_MASK = value of a card
#define SUITE_MASK 0x30 // card & SUITE_MASK = suite of a card

// Card Values
#define ACE   0x01 // Value of a(n) ace   is 1  {Rightmost 4 Bits}
#define TWO   0x02 // Value of a(n) two   is 2  {Rightmost 4 Bits}
#define THREE 0x03 // Value of a(n) three is 3  {Rightmost 4 Bits}
#define FOUR  0x04 // Value of a(n) four  is 4  {Rightmost 4 Bits}
#define FIVE  0x05 // Value of a(n) five  is 5  {Rightmost 4 Bits}
#define SIX   0x06 // Value of a(n) six   is 6  {Rightmost 4 Bits}
#define SEVEN 0x07 // Value of a(n) seven is 7  {Rightmost 4 Bits}
#define EIGHT 0x08 // Value of a(n) eight is 8  {Rightmost 4 Bits}
#define NINE  0x09 // Value of a(n) nine  is 9  {Rightmost 4 Bits}
#define TEN   0x0a // Value of a(n) ten   is 10 {Rightmost 4 Bits}
#define JACK  0x0b // Value of a(n) jack  is 11 {Rightmost 4 Bits}
#define QUEEN 0x0c // Value of a(n) queen is 12 {Rightmost 4 Bits}
#define KING  0x0d // Value of a(n) king  is 13 {Rightmost 4 Bits}

// Card Suites
#define CLUBS    0x00 // If 5th and 6th rightmost bits =  0, suite is CLUBS 
#define HEARTS   0x10 // If 5th and 6th rightmost bits = 16, suite is HEARTS
#define DIAMONDS 0x20 // If 5th and 6th rightmost bits = 32, suite is DIAMONDS
#define SPADES   0x30 // If 5th and 6th rightmost bits = 48, suite is SPADES

// Dealing Identifier
#define DEALT 0x80 // If the leftmost 2 bits = 128, card has been dealt

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