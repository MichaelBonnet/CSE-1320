/* Name of Last Editor : Michael Bonnet
 * Date of Last Edit   : 04/07/2019
 * Time of Last Edit   : 23:46 CDT (GMT-6)
 */

#ifndef UTILS_H
#define UTILS_H

/*===Structure Definitions===*/

typedef struct wordList 
{ 
	char* word; 
	char **list;                // an array of pointers to 
	                            // valid words that contain  
	                            // this word 

	int N;                      // how many words

	struct wordList *lessword;  // word less than  
	struct wordList *greatword; // word greater than 
} wordList_t; 

/*=============================*/
/*=== Function Declarations ===*/
/*=============================*/

void print(wordList_t *node);

wordList_t* search(wordList_t *node,char *word);

void insert(wordList_t **node, char* word);

void clean_up(wordList_t *node);

#endif