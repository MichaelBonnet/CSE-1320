void line1(int input) // prints the 1st line of the proper "calculator view" expression of an input digit 0-9
{
    assert(input < 10); // to be in BCD, input cannot be >1 digit, aka cannot be >9. Should have been caught in main, but whatever.
    if ( input == 0 || input == 8 || input == 9 )               { printf("%c%c%c%c%c%c", ' ', '-', '-', '-', ' ', ' '); }
    if ( input == 2 || input == 3 || input == 5 || input == 7 ) { printf("%c%c%c%c%c%c", '-', '-', '-', '-', ' ', ' '); }
    if ( input == 1 || input == 4 || input == 6 )               { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', ' ', ' '); }
}

void line2(int input) // prints the 2nd line of the proper "calculator view" expression of an input digit 0-9
{
    assert(input < 10); // to be in BCD, input cannot be >1 digit, aka cannot be >9. Should have been caught in main, but whatever.
    if ( input == 0 || input == 8 || input == 9 )               { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', '|', ' '); }
    if ( input == 1 || input == 3 )                             { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', '|', ' '); }
    if ( input == 2 || input == 7 )                             { printf("%c%c%c%c%c%c", ' ', ' ', ' ', '/', ' ', ' '); }
    if ( input == 4 || input == 5 || input == 6 )               { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', ' ', ' '); } 
}

void line3(int input) // prints the 3rd line of the proper "calculator view" expression of an input digit 0-9
{
    assert(input < 10); // to be in BCD, input cannot be >1 digit, aka cannot be >9. Should have been caught in main, but whatever.
    if ( input == 0 )                                           { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', '|', ' '); }
    if ( input == 1 )                                           { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', '|', ' '); }
    if ( input == 2 || input == 7 )                             { printf("%c%c%c%c%c%c", ' ', ' ', '/', ' ', ' ', ' '); }
    if ( input == 3 || input == 4 || input == 5 )               { printf("%c%c%c%c%c%c", '-', '-', '-', '-', ' ', ' '); }
    if ( input == 6 || input == 8 || input == 9 )               { printf("%c%c%c%c%c%c", ' ', '-', '-', '-', ' ', ' '); }
}

void line4(int input) // prints the 4th line of the proper "calculator view" expression of an input digit 0-9
{
    assert(input < 10); // to be in BCD, input cannot be >1 digit, aka cannot be >9. Should have been caught in main, but whatever.
    if ( input == 0 || input == 8 || input == 6)                { printf("%c%c%c%c%c%c", '|', ' ', ' ', ' ', '|', ' '); }
    if ( input == 1 || input == 3 || input == 5 || input == 9 ) { printf("%c%c%c%c%c%c", ' ', ' ', ' ', ' ', '|', ' '); }
    if ( input == 2 || input == 7 )                             { printf("%c%c%c%c%c%c", ' ', '/', ' ', ' ', ' ', ' '); }
    if ( input == 4 )                                           { printf("%c%c%c%c%c%c", ' ', ' ', '^', ' ', ' ', ' '); }

}

void line5(int input) // prints the 1st line of the proper "calculator view" expression of an input digit 0-9
{
    assert(input < 10); // to be in BCD, input cannot be >1 digit, aka cannot be >9. Should have been caught in main, but whatever.
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
