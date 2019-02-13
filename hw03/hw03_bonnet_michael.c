#include<stdio.h>
#include<assert.h>
// I could save 20 lines and get under 100 if I used K & R formatting, but doing it this way just makes it much more readable to me

void line1(int input) // prints the proper expression of the 5th line of each possible 0-9 digit
{
    assert(input < 10); // to be in BCD, input cannot be greater than 9. Should have been caught in main, but whatever.
    if ( input == 0 || input == 8 || input == 9 )               { printf("%c%c%c%c%c%c", ' ', '-', '-', '-', ' ', ' '); }
    if ( input == 2 || input == 3 || input == 5 || input == 7 ) { printf("%c%c%c%c%c%c", '-', '-', '-', '-', ' ', ' '); }
    if ( input == 1 || input == 4 || input == 6 )               { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', ' ', ' '); }
}

void line2(int input) // prints the proper expression of the 5th line of each possible 0-9 digit
{
    assert(input < 10); // to be in BCD, input cannot be greater than 9. Should have been caught in main, but whatever.
    if ( input == 0 || input == 8 || input == 9 )               { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', '|', ' '); }
    if ( input == 1 || input == 3 )                             { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', '|', ' '); }
    if ( input == 2 || input == 7 )                             { printf("%c%c%c%c%c%c", ' ', ' ', ' ', '/', ' ', ' '); }
    if ( input == 4 || input == 5 || input == 6 )               { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', ' ', ' '); } 
}

void line3(int input) // prints the proper expression of the 5th line of each possible 0-9 digit
{
    assert(input < 10); // to be in BCD, input cannot be greater than 9. Should have been caught in main, but whatever.
    if ( input == 0 )                                           { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', '|', ' '); }
    if ( input == 1 )                                           { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', '|', ' '); }
    if ( input == 2 || input == 7 )                             { printf("%c%c%c%c%c%c", ' ', ' ', '/', ' ', ' ', ' '); }
    if ( input == 3 || input == 4 || input == 5 )               { printf("%c%c%c%c%c%c", '-', '-', '-', '-', ' ', ' '); }
    if ( input == 6 || input == 8 || input == 9 )               { printf("%c%c%c%c%c%c", ' ', '-', '-', '-', ' ', ' '); }
}

void line4(int input) // prints the proper expression of the 5th line of each possible 0-9 digit
{
    assert(input < 10); // to be in BCD, input cannot be greater than 9. Should have been caught in main, but whatever.
    if ( input == 0 || input == 8 || input == 6)                { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', '|', ' '); }
    if ( input == 1 || input == 3 || input == 5 || input == 9 ) { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', '|', ' '); }
    if ( input == 2 || input == 7 )                             { printf("%c%c%c%c%c%c", ' ', '/', ' ', ' ', ' ', ' '); }
    if ( input == 4 )                                           { printf("%c%c%c%c%c%c", ' ', ' ', '^', ' ', ' ', ' '); }

}

void line5(int input) // prints the proper expression of the 5th line of each possible 0-9 digit
{
    assert(input < 10); // to be in BCD, input cannot be greater than 9. Should have been caught in main, but whatever.
    if ( input == 0 || input == 6 || input == 8 )               { printf("%c%c%c%c%c%c", ' ', '-', '-', '-', ' ', ' '); }
    if ( input == 1 || input == 7 || input == 9 )               { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', ' ', ' '); }
    if ( input == 2 || input == 3 ||  input ==5 )               { printf("%c%c%c%c%c%c", '-', '-', '-', '-', ' ', ' '); }
    if ( input == 4 )                                           { printf("%c%c%c%c%c%c", ' ', ' ', '^', ' ', ' ', ' '); }
}

void calculator(int array[]) // prints the calculator view of the digits in the array
{
    for (int j = 0; j < 8; j++) // loops through input array
    {
        line1(array[j]); // prints the 1st line of each digit in the input array
    }
    printf("\n"); // begins the next line on a newline
    for (int j = 0; j < 8; j++) // loops through input array
    {
        line2(array[j]); // prints the 2nd line of each digit in the input array
    }
    printf("\n"); // begins the next line on a newline
    for (int j = 0; j < 8; j++) // loops through input array
    {
        line3(array[j]); // prints the 3rd line of each digit in the input array
    }
    printf("\n"); // begins the next line on a newline
    for (int j = 0; j < 8; j++) // loops through input array
    {
        line4(array[j]); // prints the 4th line of each digit in the input array
    }
    printf("\n"); // begins the next line on a newline
    for (int j = 0; j < 8; j++) // loops through input array
    {
        line5(array[j]); // prints the 5th line of each digit in the input array
    }
    printf("\n"); // begins the next line on a newline
}


unsigned bitmask(unsigned startBit) // this function creates a mask to isolate the 4-bit sequence starting at a specified bit
{                                   // , letting us evaluate that sequence to get a packed BC digit.
    assert(startBit < 29); // makes certain we are only evaluating 8 4-bit series, aka the number of expressed digits in 8-digit BCD
    return ((1 << 4) - 1) << startBit; // left-shifts 1 by 4 to create a 4-bit isolation mask to AND with input; shifting by startBit places the mask where desired.
} 


int main(void) // the main function executes all other functions to get desired output.
{
    unsigned int input; // this is the term that the user inputs and is processed into desired output.
    int digit_storage[8]; // this array stores the terms created by the do-while loop for later use
    
    do
    {
        printf("Enter integer value: "); // prompts user for input
        scanf("%d", &input); // reads user input from stdin
        if (input == -1) // checks to see if the user wants to exit the program, done by typing -1 for input
        {
            break; // exits the loop if the user types -1, the exit condition
        }
        else
        {
            for (int i = 0; i <= 28; i+=4) // loops through each bit starting from the rightmost
            {
                digit_storage[7 - (i / 4)] = ((input & bitmask(i)) >> i); // stores the value of the isolated 4 bits in an array
                                                                          // as bit evaluation starts from the right, the array is populated backwards, from a[8] to a[0]
            }
            for (int j = 0; j < 8; j++) // loops through the newly populated array
            {
                if (digit_storage[j] > 9) { digit_storage[j] = 0; } // if the stored 4-bit binary value is greater than 9, the input integer didn't represent packed BCD, so we ignore it.
            }
            calculator(digit_storage); // prints out calculator view
        }
    } while (input != -1); // keeps prompting for input until the user types -1 to exit
    return 0;
}
