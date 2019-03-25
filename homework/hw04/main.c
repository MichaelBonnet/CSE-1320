// Header inclusions
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "constants.h"
#include "sort.h"

// main function
int main(int argc, char const *argv[])
{
	typedef struct // struct holds base and sorted versions of each input
	{
		char *word;   // the word read from the file
		char *sorted; // sorted alphabetically
	} wordStruct; // name of struct type

	wordStruct words[MAX_WORDS] = { {NULL,NULL} }; // creates array of structs to hold input
	char input[MAX_CHARS]; // temp string to hold input
	char *terminate = "-1";
	int count = 0;         // count of inputs
	int anagram_count = 0; // count of anagrams

	scanf("%s", input);
	while ( strcmp(input, terminate) != 0 )
	{
		words[count].word   = malloc( (strlen(input) + 1) * (sizeof(char)) );
		strcpy(words[count].word, input);
		words[count].sorted = sort( words[count].word, strlen(words[count].word) );
		count++;
		scanf("%s", input);
	}

	for (int i = 0; i < count; i++) // loops through each input
	{
		for (int j = i+1; j < count; j++) // loops through each input again
		{
			// checks if sorted versions are equal and that the evaluated words are not NULL
			if ( (words[j].sorted) && (words[i].sorted) && (strcmp(words[j].sorted, words[i].sorted) == 0) )
			{
				printf("%s %s\n", words[j].word, words[i].word); // prints both anagrams
				free(words[j].sorted);  // frees checked sorted version of 1st anagram
				free(words[i].sorted);  // frees checked sorted version of 2nd anagram
				free(words[j].word);    // frees checked input version of 1st anagram
				free(words[i].word);    // frees checked input version of 1st anagram
				words[j].sorted = NULL; // sets value of freed pointer to null
				words[i].sorted = NULL; // sets value of freed pointer to null
				words[j].word   = NULL; // sets value of freed pointer to null
				words[i].word   = NULL; // sets value of freed pointer to null
				anagram_count++; // increments count of pairs of anagrams found
			}
		}
	}

	printf("%d\n", anagram_count); // Displays number of pairs of anagrams found
	return 0;
}