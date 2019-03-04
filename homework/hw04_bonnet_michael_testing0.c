#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_WORDS 400000
#define MAX_CHARACTERS 1024

char** memory_allocation(void) // allocates needed memory for program
{
    char **input_words = malloc(MAX_WORDS * sizeof(char *)); // Creates an array of char pointers,
                                                             // one per string

    for (int i = 0; i < MAX_WORDS; i++)                    // allocates memory for each string
    {                                                      // according to string size
        input_words[i] = (char *)malloc(MAX_CHARACTERS+1); 
    }

    return input_words;
}

int main(void)
{
    char input[MAX_CHARACTERS];

    memory_allocation();

    int i = 0;
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

    return 0;
}