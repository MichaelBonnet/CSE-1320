#ifndef PLAYER_H
#define PLAYER_H

/*=============================*/
/*=== Function Declarations ===*/
/*=============================*/

// Prompts for and receives what the player intends to do
void player_move(int *hit, int* pass, int* _double, int* split);
// {
//  	PRECONDITIONS  : pointers passed in are not NULL
//  	POSTCONDITIONS : a move's value is set to 1 for TRUE
//  	RETURN         : none
// }

// prompts for and receives the player's bet, returning that bet as an int
int player_bet();
// {
//  	PRECONDITIONS  : none
//  	POSTCONDITIONS : a bet is made, stored in a local variable of type int
//  	RETURN         : int value of bet
// }

#endif