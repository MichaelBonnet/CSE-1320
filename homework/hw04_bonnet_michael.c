#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 400000
#define MAX_CHARACTERS 1024

// allocates necessary memory for operations
char** memory_allocation(void)
{
    // Creates an array of char pointers, one per string
    char** input_words = malloc(MAX_WORDS * sizeof(char *)); 

    // allocates memory or each string, according to string max size
    for (int i = 0; i < MAX_WORDS; i++)
    {
        input_words[i] = (char *)malloc(MAX_CHARACTERS+1); 
    }

    return input_words; // returns pointer to shiny new array of arrays
}

// adds the int values of each char in a string to get a "string value"
int string_value( char array[] )
{
	int string_value = 0;

	for (int i = 0; i < strlen(array); i++)
	{
		if (array[i] != '\0')
		{
			string_value += (int)array[i];
		}
	}
	return string_value;
}

// finds the index of the larger string value between the first and next
int LocationOfLargest( char* array[], int n )
{
	int index = 0;

	for (int i = 0; i <= n; i++)
	{
		if ( string_value(array[index]) < string_value(array[i]) )
		{
			index = i;
		}
	}
	return index;
}

// swaps the values of two strings within an array of strings
void swap( char **a, char **b )
{
	char* tmp = *a;
	*a = *b;
	*b = tmp;
}

// selection sorts an array of strings by string value
void SelectionSort( char* array[], int size )
{
	int index, last = size-1;

	while (last > 0)
	{
		index = LocationOfLargest( array, last );
		swap( &array[last], &array[index] );
		last--;
	}
}

// main function
int main(void)
{
	int anagram_count = 0; // tracks how many anagrams have been found
	char input[MAX_CHARACTERS]; // holds input from stdin
	const char *terminate = "-1"; // if this string is entered, the loop that gets input should terminate

	char **input_words = memory_allocation(); // calls memory_allocation and stores the returned pointer in input_words

	int k = 0; // counting variable
    do // loop gets input from stdin until "-1" is entered
    {
        fgets(input, MAX_CHARACTERS, stdin);
        if ( (strcmp(input, terminate) == 0) ) // exits loop if input is equal to "-1"
        {
            break;
        }
        else
        {
                strcpy(input_words[k], input); // copies string input to appropriate index in input_wods
                k++;
        }
	} while ( (strcmp(input, terminate) != 0) ); // only continues if input != "-1"

	SelectionSort( input_words, MAX_WORDS ); // selection sorts all strings in input_words

	// the following loop sees if the string values of any of the words in input_words are equal,
	// and if so, prints them and increments anagram_count;
	for (int i = 0; i < ( sizeof(input_words) / sizeof(input_words[0]) ); i++)
	{
		for (int j = 0; j < ( sizeof(input_words) / sizeof(input_words[0]) ); j++)
		{
			if ( (string_value(input_words[i]) == string_value(input_words[j])) && (i != j) )
			{
				printf("%s %s\n", input_words[i], input_words[j]);
				anagram_count++; // increments anagram_count if an anagram is found
			}
		}
	}
	printf("%d\n", anagram_count); // prints anagram_count after comparisons are complete.
	return 0; // return statement
}
