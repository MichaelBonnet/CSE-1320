#include <assert.h>
// Header inclusions
#include "bjack.h"  // Headers for this file
#include "cards.h"  // Headers from cards

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

    for (int i = 1; i < 14; i++)
    { // BEGIN FOR LOOP 0
        for (int j = 0; j < 40; j + 10)
        { // BEGIN FOR LOOP 1
            deck[i - 1 + j] = i + j;
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
     *              process each card in a for i loop
     *                  use random() to generate a number between 0 and CARDS
     *                  swap the card from deck[i] to deck[random number between 0 and CARDS]
     *              
     */

    int rand_idx;          // will hold a random number between 0 and RAND_MAX
    char temp;             // temp variable for swapping

    for (int i; i < CARDS; i++) // This is pretty much just a swap function
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

    int deck_count[52];

    for (int j = 0; j < NUM_DECKS; j++)
    { // BEGIN FOR LOOP 0
        for (int i = 0; i < 52; i++)
        { // BEGIN FOR LOOP 1
            deck[51 + ( i * j )] = deck[i];
        } // END FOR LOOP 1
    } // END FOR LOOP 0

    return 1;
} // END FUNCTION verify


// deals cards, tracks deck size, and marks a card as dealt
int deal( char *deck, char *card ) // DONE-ISH
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

    decksize = sizeof(deck) / sizeof(deck[0]);
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

    int n_vals = 0; // variable to increment as more values are calculated
    for (int i = 0; i < N; N++)
    { // BEGIN FOR LOOP 0
        value[i] = cards[i] & VALUE_MASK;
        n_vals++;
    } // END FOR LOOP 0

    *N_VALUES = n_vals; // number of values

    // test values
    // *value=21;
    // value++;
    // *value=10;
    // *N_VALUES=2;
} // END FUNCTION calculate_hand_value

