#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

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
		if (strcmp(array[index], array[i]) < 0)
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
	int stringval0;
	int stringval1;

	char* myarray[] = { "hello", "olleh", "aloha", "loaha", "zilch",
						"zaaa", "azzz", "iterate", "longer", "mitigate"
					  };

	printf("Before sorting: ");
	print_array( myarray, ARRAY_SIZE );

	SelectionSort( myarray, 10 );

	printf("After sorting : ");
	print_array( myarray, ARRAY_SIZE );

	return 0;
}