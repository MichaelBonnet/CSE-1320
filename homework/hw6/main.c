/* Name of Last Editor : Michael Bonnet
 * Date of Last Edit   : 04/07/2019
 * Time of Last Edit   : 23:46 CDT (GMT-6)
 */

/*=== Header Inclusions ===*/
#include <stdio.h>  // Standard I/O
#include <stdlib.h> // Standard Library
#include <string.h> // Strings
#include <assert.h> // Asserts
#include "utils.h"  // Header for utils.c

/*=== Main Function ===*/
int main(int argc, char const *argv[])
{
	FILE *fptr;
	fptr = fopen("words.txt", "r");
	file_check(fptr);

	fclose(fptr);

	return 0;
}