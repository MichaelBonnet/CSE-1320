/* Name of Last Editor : Michael Bonnet
 * Date of Last Edit   : 03/29/2019
 * Time of Last Edit   : 11:49 CDT (GMT-6)
 */

#ifndef BJACK_H
#define BJACK_H

/*=============================*/
/*=== Function Declarations ===*/
/*=============================*/

// Creates a deck(s) of card
void init( char *deck, int CARDS_IN_DECK );
// {
//  	PRECONDITIONS  : pointers passed in are not NULL
//                       CARDS_IN_DECK is equal to 52
//  	POSTCONDITIONS : a deck is populated
//  	RETURN         : none
// }


// Shuffles the deck
void shuffle( char *deck, int CARDS );
// {
//  	PRECONDITIONS  : pointers passed in are not NULL
//  	POSTCONDITIONS : none
//  	RETURN         : none
// }

// Confirms that the deck is properly populated (that shuffle() worked)
int verify( char *deck, int NUM_DECKS, int CARDS );
// {
//  	PRECONDITIONS  : pointers passed in are not NULL
//                       NUM_DECKS is greater than 0
//                       CARDS is greater than or equal to 52
//  	POSTCONDITIONS : a move's value is set to 1 for TRUE
//  	RETURN         : none
// }


// deals cards, tracks deck size, and marks a card as dealt
int deal( char *deck, char *card );
// {
//  	PRECONDITIONS  : pointers passed in are not NULL
//  	POSTCONDITIONS : a card marked as dealt in the deck and the dealt card is in the hand
//  	RETURN         : number of undealt cards left in deck
// }


// calculates different values for a hand of cards
void calculate_hand_value( char *cards, int N, int *value, int *N_VALUES ); 
// {
//  	PRECONDITIONS  : *cards, *value, *N_VALUES are not NULL;
//      				 N is greater than 0
//  	POSTCONDITIONS : none
//  	RETURN         : none
// }

#endif