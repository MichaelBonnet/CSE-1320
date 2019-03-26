#include <assert.h>

#include "bjack.h"
#include "cards.h"

void init( char *deck, int CARDS_IN_DECK )
{
   assert (CARDS_IN_DECK==52);
   assert (deck);

   for (int i = 1; i < 14; i++)
   {
    for (int j = 0; j < 40; j + 10)
    {
      deck[i + j] = 
    }
   }
/*
 * this function will initialize a deck of cards
 * there will be one kind of each card in the deck
 * the parameter CARDS_IN_DECK will always be 52,
 * if it is not this is a fatal error.  CARDS_IN_DECK
 * is included to provide possible future modifications.
 *
 */
}

void shuffle( char *deck, int CARDS )
{
   assert (deck);
/*
 * this function will shuffle a deck (or several) of cards.
 * one way to do this:
 *              process each card in a for i loop
 *                  use random() to generate a number between 0 and CARDS
 *                  swap the card from deck[i] to deck[random number between 0 and CARDS]
 *              
 */
   int rand_idx;
   char *temp;
   int RAND_MAX = CARDS;

   for (int i; i < CARDS; i++)
   {
    rand_idx = rand();
    strcpy(temp, deck[i]);
    strcpy(deck[i], deck[rand_idx]);
    strcpy(deck[rand_idx], temp);
   }
}

int verify( char *deck, int NUM_DECKS, int CARDS )
{
   assert (deck);
   assert (NUM_DECKS>0);
   assert (CARDS>=52);
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

   for (int i = 0; i < 52; i++)
   {

   }

   return 1;
}

int deal (char *deck, char *card)
{
   assert (deck);
   assert (card);
/*
 * this function returns two values:
 *    the return value is the number of cards left in the deck.
 *    *card is the card to be dealt.
 *
 *    (note) use a bit in the card to signify a card has been dealt,
 *    see cards.h
 */     

   return 0;
}

void calculate_hand_value (char* cards,int N, int* value, int* N_VALUES)
{
   assert(N>0);
   assert(cards);
   assert(value);
   assert(N_VALUES);
/*
 * this function calculates the different values for a hand of cards.
 * for example:
 *
 *           N = 1
 *           cards[0] = 3 of clubs
 *
 *           value[0]=3
 *           N_VALUES=1
 *
 *
 *  another example
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
    // test values
    *value=21;
    value++;
    *value=10;
    *N_VALUES=2;
}
