/* Name of Last Editor : Michael Bonnet
 * Date of Last Edit   : 04/07/2019
 * Time of Last Edit   : 23:46 CDT (GMT-6)
 */

/*=== Header Inclusions ===*/
#include <stdio.h>  // Standard I/O
#include <string.h> // Strings
#include <stdlib.h> // Standard Library
#include "utils.h"  // utilities

/*=== Function Definitions ===*/

// ???
wordList_t* search(wordList_t *node, char *word);
{
	if (node)
		return;

	if (node->word == word)
	{

	}
}

// ???
void insert(wordList_t **node, char* word);

// Traverse the tree and print all subwords and the words that contain them
void print(wordList_t *node);
{    
	// perfoms an in order traversal
	// of the tree, and prints out
	// the subword and all words
	// that contain the subword

	if (node) // If the node is valid, continue
	{  
		print( node->lessword ); // Print the lessword in the node
		if (node->N) // If the node's word count is nonzero, continue
		{  
			printf("%s [%d]\n", node->word, node->N); // print the subword and the number of words that contain it
			for ( int i = 0; i < node->N; i++ ) // iterate through all words that contain the subword
			{
			   	printf("    %s\n",node->list[i]); // print every word that contains subword
			}
		}
		print( node->greatword ); // print the greatword in the node
	}
}

// Traverse the tree and delete everything that was malloc'd
void clean_up(wordList_t *node);
{
	if (node)
		return;
	if (node->lessword)
		clean_up(node->lessword);
	if (node->greatword)
		clean_up(node->greatword);
	free(node);
}

// Check if file pointer is NULL
void file_check(FILE *fptr)
{
	if (fptr == NULL)
	{
		printf("File pointer is null!\n");
	}
}