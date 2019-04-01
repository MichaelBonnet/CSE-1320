/* Name of Last Editor : Michael Bonnet
 * Date of Last Edit   : 03/29/2019 (DD/MM/YYY)
 * Time of Last Edit   : 11:49 CDT (GMT-6)
 */

/*=== Header Inclusions ===*/
#include <stdio.h>  // Standard I/O
#include <stdlib.h> // Standard Library
#include "cards.h"  // Header for cards.c
#include "bjack.h"  // Header for bjack.c
#include "player.h" // Header for player.c

/*=== Macro/Constant Definitions ===*/
// Number of decks and number of cards in decks
#define NUM_DECKS (2)      // number of decks to be made for the game
#define CARDS_IN_DECK (52) // number of cards in a standard deck (sans jokers)

/*
 * Assignment 5 is to implement some of the low level functions
 * that will be needed for a game of blackjack.
 *
 * To learn more * about blackjack, either head to Las Vegas for
 * a long weekend, or ask wikipedia, the source of all knowledge.
 *
 * The headers and test code for each routine you need to write
 * are included in this assignment.
 *
 * Feel free to add additional tests to main.c
 *
 * At your discretion, you can add more functions.  If you think that
 * the parameters for any functions defined in this assignment need
 * to be changed, please contact the instructor.  The next assignment
 * will build on this one, so changes in the data structures or function
 * prototypes  may cause the next assignment to become more complex.
 *
 * well written and tested routines will make the follow on assignment
 * much more pleasant.
 *
 * the makefile should be functional as is.  if you need to change it,
 * feel free to do so.
 *
 * Turn in this tarball, renamed as described in assignment 4,
 * after you have implemented and tested the 'stub' functions.
 *
 */

/*=== Main Function ===*/

int main( int argc, char const *argv[] )
{ // BEGIN FUNCTION main
    // this main program will test some of the functions

    char deck[CARDS_IN_DECK*NUM_DECKS];

    init( deck, CARDS_IN_DECK );  // creates a deck of cards
    init( &deck[CARDS_IN_DECK], CARDS_IN_DECK ); // creates another deck of cards

    shuffle( deck, CARDS_IN_DECK*NUM_DECKS );  // shuffles the deck of cards

    // Checks if a deck was properly created
    if ( !verify( deck, NUM_DECKS, CARDS_IN_DECK*NUM_DECKS) )
    { // BEGIN IF 1, CONDITION TRUE
        printf("the deck is not correct\n");
    } // END IF 1, CONDITION TRUE
    else
    { // BEGIN IF 1, CONDITION FALSE
        printf("the deck is OK\n");
    } // END IF 1, CONDITION FALSE

    char hand1[2]={0}; // char array holds two chars that represent cards, each val set to 0

    hand1[0] = ACE | DIAMONDS; // first card is an ace of diamonds
    hand1[1] = THREE |SPADES;  // second card is a three of spades

    int* value;    // will hold the total value of hand
    int* n_values; // will hold the number of possible values of hand

    value = (int*) malloc (sizeof(int)*10); // malloc for the total value of hand
    n_values = (int*) malloc (sizeof(int)); // malloc for the # of possible values of hand

    calculate_hand_value (hand1,2,value,n_values); // calculates value of hand

    // Iterates through the possible values of a hand
    for (int i=0;i< *n_values;i++)
    { // BEGIN FOR LOOP 0
        print_card (hand1[i]);            // Prints the name of a card
        printf (" %d %d\n",i,*(value+i)); // Prints the potential value of a card
    } // END FOR LOOP 0

    free (value);    // Frees the memory allocated to value
    free (n_values); // Frees the memory allocated to n_values

    // put in code here to test player_move

    int* hit     = (int*) malloc (sizeof(int));
    int* pass    = (int*) malloc (sizeof(int));
    int* _double = (int*) malloc (sizeof(int));
    int* split   = (int*) malloc (sizeof(int));
    *hit        = 0;
    *pass       = 0;
    *_double    = 0;
    *split      = 0;

    player_move( hit, pass, _double, split );

    // put in code here to test deal()

    // char player1_hand[3] = {0};

    // player1_hand[0] = (TEN | DIAMONDS) | DEALT;
    // player1_hand[1] = (FIVE | SPADES)  | DEALT;

    int size = deal( deck, deck[0] );


    return 0; // Return statement
} // END FUNCTION main

