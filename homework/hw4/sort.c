// Header inclusions
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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