/* Name of Last Editor : Michael Bonnet
 * Date of Last Edit   : 03/29/2019 (DD/MM/YYY)
 * Time of Last Edit   : 11:49 CDT (GMT-6)
 */

/*=== Header Inclusions ===*/
#include <stdio.h>  // Standard I/O
#include <assert.h> // Asserts
#include "cards.h"  // Header for this file

/*=== Function Definitions ===*/

// prints a card's value and suite
void print_card( char card ) // DONE-ISH
{ // BEGIN FUNCTION print_card
	/* this function prints out a card to stout
	 * without a newline.
	 * examples
	 *       10 Diamonds
	 *       Ace Spades
	 *       4 Clubs
	 */
	
	char *value_arr[14] = { "Ace","1","2","3","4","5","6","7","8","9","10",
							 "Jack","Queen","King" };
	char *suite_arr[4] = { "CLUBS", "HEARTS", "DIAMONDS", "SPADES" };

	int card_value = card & VALUE_MASK;
	int card_suite = (card & SUITE_MASK) / 16;

	printf("%s %s", value_arr[card_value], suite_arr[card_suite]);
} // END FUNCTION print_card


// finds the value of a card
int card_value( char card )
{ // BEGIN FUNCTION card_value
	/*
	 * this function returns a numerical value of a card.
	 * the card is defined using the defined constants for
	 * suite and value.
	 *
	 * if the card is an ace, it returns a 1.
	 *
	 */

	int card_val = card & VALUE_MASK;

	return card_val;
} // END FUNCTION card_value


// checks if card is an ace
int is_ace( char card )
{ // BEGIN FUNCTION is_ace
	/*
	 * this function returns a 1 if the card is an ace.
	 * in all other situations, it returns a 0.
	 *
	 */

	int _ace = 0;
	if ( (card & VALUE_MASK) == ACE )
	{
		_ace = 1;
	}

	return _ace;
} // END FUNCTION is_ace


// Checks if the card entered has been dealt
int is_dealt( char card )
{ // BEGIN FUNCTION is_dealt
	/* 
	 * this function returns a 1 if the card has been 
	 * dealt.  otherwise, it returns a 0
	 *
	 */

	int _dealt = 0;
	if ( (card & DEALT) == DEALT )
	{
		_dealt = 1; // Returns 1 if the card has been dealt
	}

	return _dealt;
} // END FUNCTION is_dealt
