// Header Inclusions
#include <assert.h> // From standard C headers
#include "player.h" // Headers for the functions below


// Prompts for and receives what the player intends to do
void player_move(int *hit, int* pass, int* _double, int* split)
{ // BEGIN FUNCTION player_move
	assert (hit);      // Makes sure hit is not NULL
	assert (pass);     // Makes sure pass is not NULL
	assert (_double);  // Makes sure _double is not NULL
	assert (split);    // Makes sure split is not NULL
	/*
	 * this function will read an entire line (char*) from stdout and parse the
	 * words to determine what the player intends to do.
	 * use strtok() to slice the input line into tokens.
	 * the player is allowed to enter in additional words, like "I would like to split", and
	 * this function will then set the *split argument to true.
	 *
	 * another example is the player could enter "Hit Me" and this routine would set *hit
	 * argument to true;
	 *
	 * only one of hit, pass, _double, or split is set.
	 */

	char *input; // temporarily holds player input string

	// Prompt and input
	printf("What would you like to do?\n");
	scanf("%s", input);

	for (char *token = strtok(input, " "); token != NULL; token = strtok(NULL, " "))
	{ // BEGIN FOR LOOP 0
		if ( strcmp( token, "hit" )    == 0) { *hit     = 1 }; break; // Set *hit     = true
		if ( strcmp( token, "pass" )   == 0) { *pass    = 1 }; break; // Set *pass    = true
		if ( strcmp( token, "double" ) == 0) { *_double = 1 }; break; // Set *_double = true
		if ( strcmp( token, "split" )  == 0) { *split   = 1 }; break; // Set *split   = true
	} // END FOR LOOP 0
} // END FUNCTION player_move


// prompts for and receives the player's bet, returning that bet as an int
int player_bet()
{ // BEGIN FUNCTION player_bet
	int bet;            // 
	scanf("%d", &bet);
	return bet;
} // END FUNCTION player_bet
