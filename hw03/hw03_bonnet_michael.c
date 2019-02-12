#include<stdio.h>


void calculator_view(int input)
{
	char calculator[5][6];
}


unsigned bitmask(unsigned startBit)
{
	return ((1 << 4) - 1) << startBit;
}


int main(void)
{
	unsigned int input;
	int digit_storage[8];
	
	do
    {
        printf("Enter integer value: ");
        scanf("%d", &input);
        if (input == -1)
        {
            goto exiting;
        }
        else
        {
            for (int i = 0; i <= 28; i+=4)
            {
            	digit_storage[i / 4] = ((input & bitmask(i)) >> i);
            	printf("%d\n",  ((input & bitmask(i)) >> i) );
            }
            for (int i = 7; i > -1; i--)
    		{
    			printf("%d\n", digit_storage[i]);
    		}
        }
    } while (input != -1);

    exiting:
    return 0;
}
