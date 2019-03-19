// Inclusion of Header Files
#include <stdio.h>  // Standard Input/Output
#include <string.h> // String functions
#include <assert.h> // Asserts
#include <stdlib.h> // Standard Library

// Definition of Constants
#define MAX_WORDS 400000    // The max number of inputs is 400000
#define MAX_CHARACTERS 1024 // The max length of an input is 1024

/* =================================================================================================== */
/* ====================================== FUNCTION DECLARATIONS ====================================== */
/* =================================================================================================== */

char **memory_allocation(void);
/*
 * PURPOSE       : Creates a data structure for user input through memory allocation.
 * PRECONDITIONS : None.
 * POSTCONDITIONS: Returns an array of char pointers, with memory fully allocated.
 * OTHER COMMENTS: The entire purpose of this function is just to create an array
 *                 of char pointers to store user input for later use. It does so
 *                 through nice, cozy memory allocation
 */

int getUserInput(char **words);
/*
 * PURPOSE       : Gets user input and puts said input into an array.
 * PRECONDITIONS : Requires an array of strings, or, an array of char pointers.
 * POSTCONDITIONS: Returns an integer that holds the number of inputs gotten (getted?).
 * OTHER COMMENTS: 1) Unsure about this one. I usually don't use a function for user input.
 *                 2) Yes it returns an int, but in the process, it gets user input and
 *                    stores each input as a char pointer in an array.
 */

void selectionSortString(char *line, int N);
/*
 * PURPOSE       : Sorts a string in alphabetical order
 * PRECONDITIONS : Requires a char pointer and an integer. The char pointer is the string
 *                 being sorted, and the integer is the length of the string in question.
 * POSTCONDITIONS: Does not return a value, but will give the alphabetically sorted
 *                 version of the string argument.
 * OTHER COMMENTS: None.
 */


void checkAnagrams(char **input_words, int N);
/*
 * PURPOSE       : Checks an array of strings for anagrams
 * PRECONDITIONS : Requires an array of char pointers and an integer that represents
 *                 the number of char pointers.
 * POSTCONDITIONS: Does not return a value, but does print each anagram pair found
 *                 and the number of anagram pairs found.
 * OTHER COMMENTS: This is the big purpose of this program. It's the most important part.
 */


int main(void) // is void main(void) a thing?
{
    char **input_words = memory_allocation(); // creates array of char pointers for storing user input
    int count = getUserInput(input_words);    // gets user input and stores # of inputs in count

    checkAnagrams(input_words, count); // checks for anagrams within the char pointer array
    free(input_words);                 // frees allocated memory in input_words
                                       // does this free the allocated memory for each string too?
    return 0; // return statement
}

/* ================================================================================================== */
/* ====================================== FUNCTION DEFINITIONS ====================================== */
/* ================================================================================================== */

// creates a data structure for user input through memory allocation.
char **memory_allocation(void)
{
    char **input_words = malloc(MAX_WORDS*(sizeof(char*))); // creates array of char pointers

    // allocates memory for each string within the char pointer array
    for (int i = 0; i < MAX_WORDS; i++)
    {
        input_words[i] = malloc(sizeof(char)*MAX_CHARACTERS); 
    }

    return input_words; // returns the created array of char pointers to be stored
}

// Gets user input and puts said input into an array.
int getUserInput(char **words)
{
    char *throwaway;
    int count = 0;
    fgets(words[count], MAX_CHARACTERS, stdin);

    while(strcmp(words[count], "-1"))
    {
        throwaway = strtok(words[count], "\n");
        count++;
        fgets(words[count], MAX_CHARACTERS, stdin);
    }
    return count; // the total number of inputs gotten (getted?)
}

// Sorts a string in alphabetical order
void selectionSortString(char *line, int N)
{
    int smallest;
    char temp;

    for (int i = 0; i < N - 1; i++)
    {
        smallest = i;
        for (int j = i; j < N; j++)
        {
            if (line[smallest] > line[j])
            {
                smallest = j;
            }
        }
        if (smallest != i){
            temp = line[i];
            line[i] = line[smallest];
            line[smallest] = temp;
        }
    }
    return; // for some reason things get fucked up if I dont have this even though its void
}

// Checks an array of strings for anagrams
void checkAnagrams(char **input_words, int N)
{
    char *baseWord = malloc(sizeof(char)*MAX_CHARACTERS);  // Creates/allocates char pointer to store a string
    char *checkWord = malloc(sizeof(char)*MAX_CHARACTERS); // Creates/allocates char pointer to store a string
    int c = 0;
    int count = 0;
    int elements[MAX_WORDS];

    for (int i = 0; i < MAX_WORDS; i++)
    {
        elements[i] = -1;
    }

    for (int i = 0; i < N-1; i++)
    {
        if (!strcmp(input_words[i], ""))
        {
            continue;
        }

        c = 0;
        strcpy(baseWord, input_words[i]);
        selectionSortString(baseWord, strlen(baseWord));
        elements[c] = i;
        c++;
        for (int j = i + 1; j < N; j++)
        {
            if (!strcmp(input_words[i], "") || strlen(input_words[i]) != strlen(input_words[j]))
            {
                continue;
            }
            strcpy(checkWord, input_words[j]);
            selectionSortString(checkWord, strlen(checkWord));
            if (!strcmp(baseWord, checkWord))
            {
                elements[c] = j;
                count++;
                c++;
            }
        }

        if (elements[1] != -1)
        {
            int c = 0;
            while(elements[c] != -1)
            {
                printf("%s ", words[elements[c]]);
                input_words[elements[c]] = "";
                elements[c] = -1;
                c++;
            }
            printf("\n");
        }
    }

    printf("Anagrams Found: %d\n", count);

    free(baseWord);
    free(checkWord);
}
