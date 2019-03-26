#include <assert.h>

#include "player.h"

void player_move(int *hit, int* pass, int* _double, int* split)
{
   assert (hit);
   assert (pass);
   assert (_double);
   assert (split);
/*
 * this function will read an entire line (char*) from stdout and parse the
 * words to determine what the player intends to do.
 * use strtok() to slice the input line into tokens.
 * the player is allowed to enter in additional words, like "I would like to split", and this
 * function will then set the *split argument to true.
 *
 * another example is the player could enter "Hit Me" and this routine would set *hit argument
 * to true;
 *
 * only one of hit, pass, _double, or split is set.
 */
}

int player_bet()
{
/*
 * this function will prompt for and receive the players bet
 */
    return 0;
}
