#include<stdio.h>


void line1(int input)
{
	if (input == 0 | 8 | 9 )     { printf("%c%c%c%c%c%c", ' ', '-', '-', '-', ' ', ' ') }
	if (input == 2 | 3 | 5 | 7 ) { printf("%c%c%c%c%c%c", '-', '-', '-', '-', ' ', ' ') }
	if (input == 1 | 4 | 6 )     { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', ' ', ' ') }
}

void line2()
{
	if (input == 0 | 8 | 9 )     { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', '|', ' ') }
	if (input == 1 | 3 )         { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', '|', ' ') }
	if (input == 2 | 7 )         { printf("%c%c%c%c%c%c", ' ', ' ', ' ', '/', ' ', ' ') }
	if (input == 4 | 5 | 6 )     { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', ' ', ' ') } 
}

void line3()
{
	if (input == 0 )             { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', '|', ' ') }
	if (input == 1 )             { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', '|', ' ') }
	if (input == 2 | 7 )         { printf("%c%c%c%c%c%c", ' ', ' ', '/', ' ', ' ', ' ') }
	if (input == 3 | 4 | 5 )     { printf("%c%c%c%c%c%c", '-', '-', '-', '-', ' ', ' ') }
	if (input == 6 | 8 | 9 )     { printf("%c%c%c%c%c%c", ' ', '-', '-', '-', ' ', ' ') }
}

void line4()
{
	if (input == 0 | 8 | 6)      { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', '|', ' ') }
	if (input == 1 | 3 | 5 | 9 ) { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', '-', ' ') }
	if (input == 2 | 7 )         { printf("%c%c%c%c%c%c", ' ', '/', ' ', ' ', ' ', ' ') }
	if (input == 4 )             { printf("%c%c%c%c%c%c", ' ', ' ', '^', ' ', ' ', ' ') }

}

void line5()
{
	if (input == 0 | 6 | 8 )     { printf("%c%c%c%c%c%c", ' ', '-', '-', '-', ' ', ' ') }
	if (input == 1 | 7 | 9 )     { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', ' ', ' ') }
	if (input == 2 | 3 | 5 )     { printf("%c%c%c%c%c%c", '-', '-', '-', '-', ' ', ' ') }
	if (input == 4 )             { printf("%c%c%c%c%c%c", ' ', ' ', '^', ' ', ' ', ' ') }
}

void calculator(int array[])
{
	for (int i = 7;, i > -1; i--)
	{
		line1(array[i]);
	}
	printf("\n");
	for (int i = 7;, i > -1; i--)
	{
		line2(array[i]);
	}
	printf("\n");
	for (int i = 7;, i > -1; i--)
	{
		line3(array[i])
	}
	printf("\n");
	for (int i = 7;, i > -1; i--)
	{
		line4(array[i])
	}
	printf("\n");
	for (int i = 7;, i > -1; i--)
	{
		line5(array[i])
	}
	printf("\n");
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
