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
