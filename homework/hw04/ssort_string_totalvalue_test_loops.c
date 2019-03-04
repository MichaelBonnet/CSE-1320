	printf("Before sorting: ");
	print_array( myarray, ARRAY_SIZE );

	for (int a = 0; a < ARRAY_SIZE; a++)
	{
		printf("%s is %d\n", myarray[a], string_value(myarray[a]) );
	}

	SelectionSort( myarray, 10 );

	printf("After sorting : ");
	print_array( myarray, ARRAY_SIZE );

	for (int b = 0; b < ARRAY_SIZE; b++)
	{
		printf("%s is %d\n", myarray[b], string_value(myarray[b]) );
	}