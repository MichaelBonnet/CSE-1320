#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

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

void print_array( char* array[], int size )
{
	for (int i = 0; i < size; i++)
	{
		printf("%s ", array[i] );
	}
	printf("\n");
}

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

void swap( char* *a, char* *b )
{
	char* tmp = *a;
	*a = *b;
	*b = tmp;
}

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

int main(void)
{
	int anagram_count = 0;

	char* myarray[] = { "hello", "olleh", "aloha", "loaha", "zilch",
						"zaaa", "azzz", "iterate", "longer", "mitigate"
					  };

	SelectionSort( myarray, 10 );

	for (int i = 0; i < ( sizeof(myarray) / sizeof(myarray[0]) ); i++)
	{
		for (int j = 0; j < ( sizeof(myarray) / sizeof(myarray[0]) ); j++)
		{
			if ( (string_value(myarray[i]) == string_value(myarray[j])) && (i != j) )
			{
				printf("%s %s\n", myarray[i], myarray[j]);
				anagram_count++;
			}
		}
	}
	printf("%d\n", anagram_count);
	return 0;
}