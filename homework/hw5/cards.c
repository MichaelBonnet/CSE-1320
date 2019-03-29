#include <stdio.h>
#include <assert.h>

#include "cards.h"

// prints a card's value and suite
void print_card( char card )
{ // BEGIN FUNCTION print_card
	/* this function prints out 
	 * a card to stdout.  without a newline.
	 * examples
	 *       10 Diamonds
	 *       Ace Spades
	 *       4 Clubs
	 */
} // END FUNCTION print_card

// finds the value of a card
int card_value( char card ) // DONE-ISH
{ // BEGIN FUNCTION card_value
	/*
	 * this function returns a numerical value of a card.
	 * the card is defined using the defined constants for
	 * suite and value.
	 *
	 * if the card is an ace, it returns a 1.
	 *
	 */
	int card_value = card & VALUE_MASK;

	return card_value;
} // END FUNCTION card_value


// checks if card is an ace
int is_ace( char card ) // DONE-ISH
{ // BEGIN FUNCTION is_ace
	/*
	 * this function returns a 1 if the card is an ace.
	 * in all other situations, it returns a 0.
	 *
	 */
	if ( (card & VALUE_MASK) == 1 ) { return 1; }

	return 0;
} // END FUNCTION is_ace


// Checks if the card entered has been dealt
int is_dealt( char card ) // DONE-ISH
{ // BEGIN FUNCTION is_dealt
	/* 
	 * this function returns a 1 if the card has been 
	 * dealt.  otherwise, it returns a 0
	 *
	 */

	if ( (card & DEALT) != 0 ) { return 1; }

   return 0;
} // END FUNCTION is_dealt
