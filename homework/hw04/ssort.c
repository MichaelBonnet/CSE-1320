#include <stdio.h>
#define ARRAY_SIZE 10

void print_array( int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i] );
	}
	printf("\n");
}

int LocationOfLargest( int array[], int n )
{
	int index = 0;

	for (int i = 0; i <= n; i++)
	{
		if (array[index] < array[i])
		{
			index = i;
		}
	}
	return index;
}

void swap( int *a, int *b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void SelectionSort( int array[], int size )
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
	int myarray[ARRAY_SIZE] = {21, 45, 13, 5, 19, 2, 7, 11, 4, 15};

	printf("Before sorting: ");
	print_array( myarray, ARRAY_SIZE );

	SelectionSort( myarray, 10 );

	printf("After sorting: ");
	print_array( myarray, ARRAY_SIZE );

	return 0;
}