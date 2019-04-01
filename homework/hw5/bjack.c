/* Name of Last Editor : Michael Bonnet
 * Date of Last Edit   : 03/29/2019 (DD/MM/YYY)
 * Time of Last Edit   : 11:49 CDT (GMT-6)
 */

/*=== Header Inclusions ===*/
#include <assert.h> // Asserts
#include <stdlib.h> // Standard Library
#include "bjack.h"  // Header for this file
#include "cards.h"  // Header for cards.c
#include "player.h" // Header for player.c

/*=== Function Definitions ===*/

// Creates a deck(s) of card
void init( char *deck, int CARDS_IN_DECK ) // DONE-ISH
{ // BEGIN FUCNTION init
    assert(CARDS_IN_DECK==52); // CARDS_IN_DECK must = 52
    assert(deck);              // Make sure deck is not NULL

    /*
     * this function will initialize a deck of cards
     * there will be one kind of each card in the deck
     * the parameter CARDS_IN_DECK will always be 52,
     * if it is not this is a fatal error.  CARDS_IN_DECK
     * is included to provide possible future modifications.
     *
     */

    char suite_arr[4]  = { CLUBS, HEARTS, DIAMONDS, SPADES };
    char value_arr[13] = { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

    int idx = 0;
    for ( int i = 0; i < 4; i++ )
    { // BEGIN FOR LOOP 0
        for ( int j = 1; j < 13; j++ )
        { // BEGIN FOR LOOP 1
            deck[idx] = value_arr[j] | suite_arr[i]; // sets next card to the next value in order
            idx++;
        } // END FOR LOOP 1
    } // END FOR LOOP 0

} // END FUNCTION init


// Shuffles the deck
void shuffle( char *deck, int CARDS ) // DONE-ISH
{ // BEGIN FUNCTION shuffle
    assert(deck); // Makes sure deck is not NULL

    /*
     * this function will shuffle a deck (or several) of cards.
     * one way to do this:
     *     process each card in a for i loop
     *         use random() to generate a number between 0 and CARDS
     *         swap the card from deck[i] to deck[random number between 0 and CARDS]
     *              
     */

    int rand_idx;          // will hold a random number between 0 and RAND_MAX
    char temp;             // temp variable for swapping

    for ( int i; i < CARDS; i++ ) // This is pretty much just a swap function
    { // BEGIN FOR LOOP 0
        rand_idx = rand() % (CARDS + 1); // random integer in range [0, CARDS]
        temp           = deck[i];
        deck[i]        = deck[rand_idx];
        deck[rand_idx] = temp;
    } // END FOR LOOP 0
} // END FUNCTION shuffle


// Confirms that the deck is properly populated (that shuffle() worked)
int verify( char *deck, int NUM_DECKS, int CARDS ) // DONE-ISH
{ // BEGIN FUNCTION verify
    assert(deck);
    assert(NUM_DECKS>0);
    assert(CARDS>=52);

    /* 
     * this function will verify that the deck has the correct
     * type of cards.  this is to ensure that the shuffle routine 
     * was correct, and did not duplicate or remove any cards.
     *
     * suggestion:  use an array to count how many of each card type
     * is in the deck.
     *
     * return value is a 1 if the deck is good, otherwise it returns a
     * 0
     *
     */
    
    int suite_count[4]  = {0};
    int value_count[13] = {0};

    char suite_temp;
    char value_temp;

    for ( int i = 0; i < CARDS; i++ )
    { // BEGIN FOR LOOP 0
        suite_temp = deck[i] & SUITE_MASK;
        value_temp = deck[i] & VALUE_MASK;

        suite_count[ (suite_temp / 16) - 1 ]++;
        value_count[ value_temp - 1 ]++;
    } // END FOR LOOP 0

    for ( int j = 0; j < 4; j++ )
    {
        if ( suite_count[j] != (13 * NUM_DECKS) )
        {
            return 0;
        }
    }

    for ( int k = 0; k < 13; k++ )
    {
        if ( value_count[k] != (4 * NUM_DECKS) )
        {
            return 0;
        }
    }

    return 1;
} // END FUNCTION verify


// deals cards, tracks deck size, and marks a card as dealt
int deal( char* deck, char* card ) // DONE-ISH
{ // BEGIN FUNCTION deal
    assert(deck);
    assert(card);

    /*
     * this function returns two values:
     *    the return value is the number of cards left in the deck.
     *    *card is the card to be dealt.
     *
     *    (note) use a bit in the card to signify a card has been dealt,
     *    see cards.h
     */     

    int decksize = sizeof(deck) / sizeof(deck[0]);
    decksize -= 1;

    *card = *card | DEALT;

    return decksize;
} // END FUNCTION deal


// calculates different values for a hand of cards
void calculate_hand_value( char* cards, int N, int* value, int* N_VALUES ) // DONE-ISH
{ // BEGIN FUNCTION calculate_hand_value
    assert(N>0);       // make sure N is greater than 0
    assert(cards);     // make sure cards is not NULL
    assert(value);     // make sure value is not NULL
    assert(N_VALUES);  // make sure N_VALUES is not NULL

    /*
     * this function calculates the different values for a hand of cards.
     * Example 1:
     *
     *           N = 1
     *           cards[0] = 3 of clubs
     *
     *           value[0]=3
     *           N_VALUES=1
     *
     * Example 2:
     *
     *          N = 2
     *          cards[0]=10 diamonds
     *          cards[1]=ace of spades
     *
     *          value[0] = 11  
     *          value[1] = 21
     *          N_VALUES = 2
     *
     *
     * there are some functions in cards.h that will help you here.
     */


    // Determining if there is an ace in the passed in hand
    int ace_present;
    for ( int i = 0; i < N; i++ )
    { // BEGIN FOR LOOP 0
        if ( (cards[i] & VALUE_MASK) == ACE )
        { // BEGIN IF 0, CONDITION TRUE
            ace_present = 1; // there is an ace in the hand
        } // END IF 0, CONDITION TRUE
        else
        { // BEGIN IF 0, CONDITION FALSE
            ace_present = 0; // there is not an ace in the hand
        } // END IF 0, CONDITION TRUE
    } // END FOR LOOP 0


    // Value calculation is there is an ace
    if ( ace_present == 1 )
    { // BEGIN IF 0, CONDITION TRUE
        *N_VALUES = 2; // Sets number of possible values given the presence of an ace
        if ( N == 1 )
        { // BEGIN IF 1.0, CONDITION TRUE
            value[0] = ( cards[0] & VALUE_MASK ) + 10;
        } // END IF 1.0, CONDITION TURE
        if ( N == 2 )
        { // BEGIN IF 1.1, CONDITION TRUE
            value[0] = ( cards[0] & VALUE_MASK ) + ( cards[1] & VALUE_MASK );
            value[1] = ( cards[0] & VALUE_MASK ) + ( cards[1] & VALUE_MASK ) + 10;
        } // END IF 1.1, CONDITION TRUE
    } // END IF 0, CONDITION TRUE


    // Value calculation if there is no ace
    if ( ace_present == 0 )
    { // BEGIN IF 0, CONDITION TRUE
        *N_VALUES = 1; // Sets number of possible values given the presence of an ace
        for (int i = 0; i < N; i++)
        { // BEGIN FOR LOOP 0
            value[0] += ( cards[i] & VALUE_MASK );
        } // END FOR LOOP 0
    } // END IF 0, CONDITION TURE

    // test values
    // *value=21;
    // value++;
    // *value=10;
    // *N_VALUES=2;
} // END FUNCTION calculate_hand_value

