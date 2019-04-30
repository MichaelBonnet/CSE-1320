// Name of Last Editor : Michael Bonnet
// Date of Last Edit   : 04/30/2019 (DD/MM/YYY)
// Time of Last Edit   : 16:39 Central Daylight Time (GMT-6)


/*=========================*/
/*=== Header Inclusions ===*/
/*=========================*/


#include <stdio.h>  // Standard I/O
#include <string.h> // String Functions
#include <stdlib.h> // Standard Library
#include <assert.h> // Asserts


/*==================================*/
/*=== Macro/Constant Definitions ===*/
/*==================================*/


// The number of reserved words in C
#define RESERVED_WORDS 44

/*========================*/
/*=== Global Variables ===*/
/*========================*/


// An array of strings (double char pointer) that holds each reserved word in C as a string
char *globalBank[RESERVED_WORDS] = {
                            "auto", "break", "case", "char", "const", "continue", "default",
                            "do", "double", "else", "enum", "extern", "float", "for", "goto",
                            "if", "inline", "int", "long", "register", "restrict", "return",
                            "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
                            "union", "unsigned", "void", "volatile", "while", "_Alignas", "_Alignof",
                            "_Atomic", "_Bool", "_Complex", "_Generic", "_Imaginary", "_NoReturn",
                            "_Static_assert", "_Thread_local"
                            };


// An array of integers (int pointer) where each element represents the # of a reserved word found
int globalCounts[RESERVED_WORDS] = {0}; 


/*=============================*/
/*=== Function Declarations ===*/
/*=============================*/


// Checks if a word found in a file is a reserved word, then increments the array members matching the reserved word
void checkForReserved( char *word, int *localCounts );
// {
//      PRECONDITIONS  : pointers passed in are not NULL
//      POSTCONDITIONS : none
//      RETURN         : none (void)
//      COMMENTS       : array members incremented are in globalCounts and localCounts
// }


// Prints the passed-in word and the number of times it was found in the file.
void printCounts(char *word, int count);
// {
//      PRECONDITIONS  : pointers passed in are not NULL
//      POSTCONDITIONS : none
//      RETURN         : none (void)
//      COMMENTS       : prints the (count)th element of an array 
// }


// Frees and NULLs a char pointer because I hate writing two lines for it every time
void char_megafree( char* pointer );
// {
//      PRECONDITIONS  : pointers passed in are not NULL, though it is 
//                       not checked with assert because it's getting nuked anyway
//      POSTCONDITIONS : none
//      RETURN         : none (void)
//      COMMENTS       : yeah just does all the work of freeing a pointer
// }

// Frees and NULLs a FILE pointer because I hate writing two lines for it every time
void file_megafree( FILE* pointer );
// {
//      PRECONDITIONS  : pointers passed in are not NULL, though it is 
//                       not checked with assert because it's getting nuked anyway
//      POSTCONDITIONS : none
//      RETURN         : none (void)
//      COMMENTS       : yeah just does all the work of freeing a pointer
// }


// Frees and NULLs an int pointer because I hate writing two lines for it every time
void int_megafree( int* pointer );
// {
//      PRECONDITIONS  : pointers passed in are not NULL, though it is 
//                       not checked with assert because it's getting nuked anyway
//      POSTCONDITIONS : none
//      RETURN         : none (void)
//      COMMENTS       : yeah just does all the work of freeing a pointer
// }


// Checks if  file is of the correct type
int checkfile(char* filename);
// {
//      PRECONDITIONS  : pointers passed in are not NULL, though it is
//      POSTCONDITIONS : none
//      RETURN         : int that equals 0 for invalid file or 1 for valid file
//      COMMENTS       : makes sure only correct files are analyzed
// }


// Analyzes all input files for reserved words
void fileAnalysis( int argc, char** argv );
// {
//      PRECONDITIONS  : pointers passed in are not NULL
//      POSTCONDITIONS : none
//      RETURN         : none (void)
//      COMMENTS       : pretty much does all the heavy lifting. 
//                       idk why I made it its own function. Fun, maybe?
// }

// Prints each reserved word and the number of times it was found in all files.
void printGlobalCounts( int* globalCounts, char** globalBank );
// {
//      PRECONDITIONS  : pointers passed in are not NULL
//      POSTCONDITIONS : none
//      RETURN         : none (void)
//      COMMENTS       : basically just uses the printCounts function for the global counts.
// }

// Prints each reserved word and the number of times it was found in each file.
void printLocalCounts( int* localCounts, char** globalBank );
// {
//      PRECONDITIONS  : pointers passed in are not NULL
//      POSTCONDITIONS : none
//      RETURN         : none (void)
//      COMMENTS       : basically just uses the printCounts function for the local counts.
// }


/*=====================*/
/*=== Main Function ===*/
/*=====================*/

int main( int argc, char *argv[] )
{ // START FUNCTION main
    fileAnalysis(argc, argv);                     // See function description
    printGlobalCounts(globalCounts, globalBank);  // See function description
    return 0;
} // END FUNCTION main


/*============================*/
/*=== Function Definitions ===*/
/*============================*/

// Checks if a word found in a file matches a reserved word,
// then increments the array members matching the reserved word
void checkForReserved( char *word, int *localCounts )
{ // START FUNCTION checkForReserved
    assert(word);        // check that it is not null
    assert(localCounts); // check that it is not null

    for( int i = 0; i < RESERVED_WORDS; i++ )
    {
        if(!strcmp( word, globalBank[i] ))
        {
            globalCounts[i]++;
            localCounts[i]++;
            return;
        }
    }
} // END FUNTION checkForReserved


// Prints the passed-in word and the number of times it was found in the file.
void printWordCount(char *word, int count)
{ // START FUNCTION printWordCount
    assert(word); // check that it is not null

    printf("%s: %d\n", word, count);
} // END FUNCTION printWordCount 


// Frees and NULLs a char pointer because I hate writing two lines for it every time
void char_megafree( char* pointer )
{ // START FUNCTION megafree 
    free( pointer );
    pointer = NULL;
} // END FUNCTION megafree


// Frees and NULLs a FILE pointer because I hate writing two lines for it every time
void file_megafree( FILE* pointer )
{ // START FUNCTION megafree 
    free( pointer );
    pointer = NULL;
} // END FUNCTION megafree


// Frees and NULLs a int pointer because I hate writing two lines for it every time
void int_megafree( int* pointer )
{ // START FUNCTION megafree 
    free( pointer );
    pointer = NULL;
} // END FUNCTION megafree


// Checks if  file is of the correct type
int checkfile(char* filename)
{ // START FUNCTION checkFile
    assert(filename); // check that it is not null

    char* ext = strrchr(filename, '.');
    if ( *(ext) && ( !strcmp( (ext + 1), "h") || !strcmp( (ext + 1), "c") ) && !(*(ext + 2)) ) // see Footnote 1
    {
        return 1; // returns 1 if file is indeed .c or .h, indicating positive check
    }
    else
    {
        return 0; // returns 0 if file is not .c or .h, indicating negative check
    }
} // END FUNCTION checkFile


// Analyzes all input files for reserved words
void fileAnalysis( int argc, char** argv )
{ // START FUNCTION file_analysis
    assert(argv); // check that it is not null

    FILE *file;
    char *input = (char*)malloc(sizeof(char)*1024);
    char *chunk  = (char*)malloc(sizeof(char)*1024);

    for ( int i = 1; i < argc; i++ )
    {

        if ( checkfile(argv[i]) ) // this checks if the file is of desired type.
        {
            int localCounts[RESERVED_WORDS] = {0};

            file = fopen(argv[i], "r");
            printf("File name is %s\n", argv[i]);

            while( fscanf(file, "%s", input) != EOF )
            {
                for (char *chunk = strtok(input, " "); chunk != NULL; chunk = strtok(NULL, " "))
                { // BEGIN FOR LOOP 0
                    checkForReserved(chunk, localCounts);
                } // END FOR LOOP 0
            }

            printLocalCounts(localCounts, globalBank);

            fclose(file);
        }
    }

    file_megafree(file);
    char_megafree(input);
    char_megafree(chunk);
} // END FUNCTION fileAnalysis


// Prints each reserved word and the number of times it was found in all files.
void printGlobalCounts( int* globalCounts, char** globalBank )
{ // START FUNCTION printGlobalCounts
    assert(globalCounts); // check that it is not null
    assert(globalBank);   // check that it is not null

    printf("Global Counts: \n");
    for( int i = 0; i < RESERVED_WORDS; i++ )
    {
        if(globalCounts[i])
        {
            printWordCount( globalBank[i], globalCounts[i] );
        }
    }
} // END FUNCTION printGlobalCounts

// Prints each reserved word and the number of times it was found in each file.
void printLocalCounts( int* localCounts, char** globalBank )
{ // START FUNCTION printLocalCounts
    assert(localCounts); // check that it is not null
    assert(globalBank);  // check that it is not null

    for( int k = 0; k < RESERVED_WORDS; k++ )
    {
        if(localCounts[k])
        {
            printWordCount(globalBank[k], localCounts[k]);
        }
    }
} // END FUNCTION printLocalCounts