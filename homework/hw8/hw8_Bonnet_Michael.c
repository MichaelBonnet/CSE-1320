/*=== Header Inclusions ===*/
#include <stdio.h>  // Standard I/O
#include <stdlib.h> // Standard Library

/*=== Function Definitions ===*/

// Squares each element in a 2D array and returns the sum of all
int sumsquares(int rows, int columns, int *arr) 
{ 
    int sum = 0; 
    for ( int i = 0; i < (rows * columns); i++ ) // rows times columns = number of elements in the array,
    {                                            // which are each 1 chunk after the other because
        sum += ( *(arr + i) * *(arr + i) );      // C doesn't really have multidimensional arrays
    }  
    return sum;
} 

/*=== Main Function ===*/
int main( int argc, char const *argv[] )
{
	int rows = 2;
	int columns = 4;
	int nums[][4] = { { 23, 12, 14, 3}, { 31, 25, 41, 17} };
    int *arr = &nums[0][0]; // address of first element = address of entire array

	int sumofsquares = sumsquares(rows, columns, arr);

	printf( "Sum of Each Array Element Squared : %d\n", sumofsquares );
	printf( "Expected Number                   : 4434\n");

	return 0;
}