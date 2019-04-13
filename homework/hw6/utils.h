/* Name of Last Editor : Michael Bonnet
 * Date of Last Edit   : 04/07/2019
 * Time of Last Edit   : 23:46 CDT (GMT-6)
 */

#ifndef UTILS_H
#define UTILS_H

/*===Structure Definitions===*/

typedef struct wordList 
{ 
	char* word;                 // the subword in question

	char **list;                // an array of pointers to 
	                            // valid words that contain  
	                            // this word 

	int N;                      // how many words

	struct wordList *lessword;  // word less than  
	struct wordList *greatword; // word greater than 
} wordList_t; 

/*=== Function Declarations ===*/

// ???
wordList_t* search(wordList_t *node,char *word);
// {
//  	PRECONDITIONS  : ?????????
//  	POSTCONDITIONS : ?????????
//  	RETURN         : a struct wordList_t pointer to where word was found
//		COMMENTS       : honestly no fucking clue what to do here
// }

// ???
void insert(wordList_t **node, char* word);
// {
//  	PRECONDITIONS  : node and word are not null
//  	POSTCONDITIONS : data is inserted into the tree
//  	RETURN         : none
//		COMMENTS       : honestly no fucking clue what to do here
// }

// Traverse the tree and print all subwords and the words that contain them
void print(wordList_t *node);
// {
//  	PRECONDITIONS  : Node is not null
//  	POSTCONDITIONS : none
//  	RETURN         : none
//		COMMENTS       : prints all the things
// }

// Traverse the tree and delete everything that was malloc'd
void clean_up(wordList_t *node);
// {
//  	PRECONDITIONS  : Node is not null
//  	POSTCONDITIONS : Everything that was malloc'd is deleted
//  	RETURN         : none
//		COMMENTS       : frees up memory and such
// }

// Check if file pointer is NULL
void file_check(FILE* fptr);
// {
//  	PRECONDITIONS  : none
//  	POSTCONDITIONS : none
//  	RETURN         : none
//		COMMENTS       : really just to make sure we don't start fucking with NNULL
// }
#endif