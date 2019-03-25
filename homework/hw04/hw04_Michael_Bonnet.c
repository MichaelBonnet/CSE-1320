// Header inclusions
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Constant/Macro Definitions
#define MAX_WORDS 400000  // max number of words that can be entered
#define MAX_CHARS 1024    // max length of a word that can be entered

// determines index of greater value between two chars
int locateLargest(char *word, int n);

// swaps locations of two characters
void swap(char *a, char *b);


// creates new string of sorted characters in input string
char *sort(char *word, int size);


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
	int count = 0; // count of inputs
	int anagram_count = 0; // count of anagrams

	scanf("%s", input);
	while ( strcmp(input, terminate) != 0 )
	{
		words[count].word   = malloc( (strlen(input) + 1) * (sizeof(char)) );
		//words[count].sorted = malloc( (strlen(input) + 1) * (sizeof(char)) );

		strcpy(words[count].word, input);
		words[count].sorted = sort( words[count].word, strlen(words[count].word) );
		count++;
		scanf("%s", input);
	}

	// for (int j = 0; j < count; j++)
	// {
	// 	printf("%s %s\n", words[j].word, words[j].sorted);
	// }

	for (int i = 0; i < count; i++) // loops through each input
	{
		for (int j = i+1; j < count; j++) // loops through each input again
		{
			//printf("%s %d %s %d\n", words[j].sorted, j, words[i].sorted, i);
			if ( (words[j].sorted) && (words[i].sorted) && (strcmp(words[j].sorted, words[i].sorted) == 0) )  // checks if sorted versions are equal
			{
				printf("%s %s\n", words[j].word, words[i].word); // prints both anagrams
				free(words[j].sorted); // frees checked sorted version of 1st anagram
				free(words[i].sorted); // frees checked sorted version of 2nd anagram
				free(words[j].word);   // frees checked input version of 1st anagram
				free(words[i].word);   // frees checked input version of 1st anagram
				words[j].sorted = NULL;
				words[i].sorted = NULL;
				words[j].word   = NULL;
				words[i].word   = NULL;
				anagram_count++; // increments count of anagrams found
			}
		}
	}

	printf("%d\n", anagram_count);

	return 0;
}

// determines index of greater value between two chars
int locateLargest(char *word, int n)
{
    int index = 0;

    for (int i = 0; i <= n; i++)
    {
        if (*(word + index) < *(word + i))
        {
            index = i;
        }
    }
    return index;
}

// swaps locations of two characters
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// creates new string of sorted characters in input string
char *sort(char *word, int size)
{
    assert(word != NULL);
    assert(size != 0);
    
    char *sorted = malloc((size + 1) * sizeof(char));
    strcpy(sorted, word);
    int index, last = size - 1;

    while (last > 0)
    {
        index = locateLargest(sorted, last);
        swap( (sorted + last) , (sorted + index) );
        last--;
    }
    *(sorted + size) = '\0';
    return sorted;
}