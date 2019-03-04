#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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


// Sort an array of Strings into alphabetical order
void string_selection_sort(char array[])
{
    // Find the string reference that should go in each index of
    // the array, from index 0 to the end
    for (int j = 0; j < MAX_WORDS-1; j++)
    {
        // Find min: the index of the string reference that should go into cell j.
        // Look through the unsorted strings (those at j or higher) for the one that is first in lexicographic order
        int min = j;
        for (int k = j + 1; k < MAX_WORDS; k++)
        {
            if (array[k] < array[min]) // array[min] is the current min value
            {
                min = k; // shifts value of index min down by 1 index
            }
            // swap value at index j with value at index min
            char temp = array[j];
            array[j] = array[min];
            array[min] = temp;
        }
    }
}

// Sort an array of characters (a string) into alphabetical order
void character_selection_sort(char array[])
{
    // Find the character reference that should go in each index of
    // the array, from index 0 to the end
    for(int i = 0; i < MAX_CHARACTERS-1; i++)
    {
        // Find min: the index of the character reference that should go into index i.
        // Look through the unsorted strings (those at i or higher) for the one that is first in lexicographic order
        int min = i;
        for(int j = i + 1; j < MAX_CHARACTERS; j++)
        {
            if(array[j]<array[min]) // array[min] is the current min value
            {
                min = j; // shifts value of index min down by 1 index
            }
            // swap value at index i with value at index min
            char temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}


// Main function that executes all other functions to get desired output
int main(void)
{
    char input[MAX_CHARACTERS];

    // calls memory allocation function that returns a pointer to
    // the nice shiny array of arrays, and stores it.
    char **input_words = memory_allocation();

    // continually asks for input until exit command is received,
    // storing input in successive indexes of input_words
    int i = 0; // counting variable
    do
    {
        scanf("%s", input);
        if (*input == -1)
        {
            break;
        }
        else
        {
                strncpy(input_words[i], input, MAX_CHARACTERS);
                i++;
        }
    } while (i < MAX_WORDS-1);

    // Sorts strings in input_words alphabetically
    string_selection_sort(input_words[]);

    // Sorts characters in each string alphabetically
    for (int j = 0; j < MAX_WORDS; j++)
    {
        character_selection_sort(input_words[j]);
    }

    for (int l = 0; l < MAX_WORDS; l++)
    {
        printf("%s\n", *input_words);
    } 

    return 0; // Return statement
}