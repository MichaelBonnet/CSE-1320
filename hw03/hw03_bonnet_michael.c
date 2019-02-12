#include<stdio.h>


char calculator[5][6];

unsigned bitmask(unsigned startBit)
{
	return ((1 << 4) - 1) << startBit;
}


int main(void)
{
	unsigned int input;
	
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
            for (unsigned int i = 0; i <= 28; i+=4)
            {
            	printf("%x\n",  ((input & bitmask(i)) >> i) );
            }        
        }
    } while (input != -1);

    exiting:
    return 0;
}
