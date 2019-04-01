/* Name of Last Editor : Michael Bonnet
 * Date of Last Edit   : 03/29/2019 (DD/MM/YYY)
 * Time of Last Edit   : 11:49 CDT (GMT-6)
 */

/*=== Header Inclusions ===*/
#include <assert.h> // Asserts
#include <stdio.h>  // Standard I/O
#include <string.h> // String functions
#include <stdlib.h> // Standard Library
#include "player.h" // Header for this file
#include "cards.h"  // Header for cards.c

/*=== Function Definitions ===*/

// Prompts for and receives what the player intends to do
void player_move(int *hit, int* pass, int* _double, int* split) // DONE-ISH
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

	// Prompts for and reads input
	char input[1024];
	printf("What would you like to do?\n");
	scanf("%s", input);

	// Loops through all tokens in the input string to see what the player wants to do
	for (char *token = strtok(input, " "); token != NULL; token = strtok(NULL, " "))
	{ // BEGIN FOR LOOP 0
		if ( strcmp( token, "hit" )    == 0) { *hit     = 1; }; break; // Set *hit     = true
		if ( strcmp( token, "pass" )   == 0) { *pass    = 1; }; break; // Set *pass    = true
		if ( strcmp( token, "double" ) == 0) { *_double = 1; }; break; // Set *_double = true
		if ( strcmp( token, "split" )  == 0) { *split   = 1; }; break; // Set *split   = true
	} // END FOR LOOP 0
} // END FUNCTION player_move


// prompts for and receives the player's bet, returning that bet as an int
int player_bet() // DONE-ISH
{ // BEGIN FUNCTION player_bet
	int bet;            // 
	scanf("%d", &bet);
	return bet;
} // END FUNCTION player_bet
