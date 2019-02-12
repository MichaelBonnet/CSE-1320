#include<stdio.h>
// this creates a pseudo-BCD by multiplying each of a base 10 number's
// digits by the same degree hex place values as the digit's decimal place value.
int int_to_bcd(int input)
{
	int total = 0;
	int placevalue = 1;

	while (input > 0)
	{
	total += (input % 10) * placevalue;
	placevalue *= 16;
	input /= 10;
	}
	return total;
}

int power(int base, int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
 }

// int masking_and_shifting(int input)
// {
// 	int placevalue = 1;
// 	while (remaining > 0)
// 	{
// 		remaining -= (remaining % 16) * placevalue;
// 		placevalue++;
// 	}
// }

// void masking(void)
// {
// 	for (int i = 0, i < 8, i++)
// 	{
// 		printf("%x", (15 * pow(16, 7-i)));
// 	}
// }

int main(void)
{
	int input;
	int input_bcd;
	int mask;
	
	do
    {
        printf("Enter positive integer value: ");
        scanf("%d", &input);
        if (input == -1 || input < 0)
        {
            goto exiting;
        }
        else
        {
            input_bcd = int_to_bcd(input);
            for (int i = 0; i < 8; i++)
			{
				mask = (15 * power(16, 7-i));
				printf("Value: %x\n", ((input_bcd & mask) >> (i * 4)));
			}
            
        }
    } while (input != -1 || input > -1);
    exiting:
    return 0;
}
