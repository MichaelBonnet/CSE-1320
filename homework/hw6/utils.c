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

void print(wordList_t *node);

wordList_t* search(wordList_t *node,char *word);

void insert(wordList_t **node, char* word);

void clean_up(wordList_t *node);