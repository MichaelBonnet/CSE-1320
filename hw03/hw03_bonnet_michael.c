#include<stdio.h>


void calculator_view(int input)
{
	char calculator[5][6];
}


// this function creates a mask to isolate the 4-bit sequence starting at a specified bit.
unsigned bitmask(unsigned startBit)
{
	return ((1 << 4) - 1) << startBit;
} 


// the main function executes all other functions to get desired output.
int main(void)
{
	unsigned int input; // this is the term that the user inputs and is processed into desired output.
	int digit_storage[8]; // this array stores the terms created by the do-while loop for later use
	
	do
    {
        printf("Enter integer value: "); // prompts user for input
        scanf("%d", &input); // reads user input from stdin
        if (input == -1)
        {
            break; // exits the loop if the user types -1, the exit condition
        }
        else
        {
            for (int i = 0; i <= 28; i+=4) // loops through each bit starting from the rightmost
            {
            	digit_storage[i / 4] = ((input & bitmask(i)) >> i); // stores the value of the rightshifted 4 bits in an array
            	printf("%d\n",  ((input & bitmask(i)) >> i) );
            }
            for (int i = 7; i > -1; i--)
    		{
    			printf("%d\n", digit_storage[i]);
    		}
        }
    } while (input != -1); // keeps prompting for input until the user types -1 to exit
    return 0;
}
