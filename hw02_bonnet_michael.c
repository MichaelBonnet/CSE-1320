#include <stdio.h>

#include <assert.h>

#define __USE_MISC

#include <math.h>

// need to somehow bring this code into init() and then make sin_() be my linear interpolation thing
float sin_(float input_angle)
{
	int i;
	float x, sum=0, term, numerator, denominator;

	if (input_angle >= 0.0 && input_angle < 360.0)
	{
		x = input_angle * (M_PI/180);
		numerator = x;
		denominator = 1;
		i = 2;

		do
		{
			term = numerator / denominator;

			numerator = -numerator * x * x;
			denominator = denominator * i * (i+1);
			sum = sum + term;
			// add a counter somehow to be tracked by while() in order to limit it to the first 4 terms?
			// int j = 0, j++
			// while j < 4, continue
		} while (fabs(term)>= 0.00001);

		return sum;
	}
		else
		{
			return 0.0;
		}
}

// This function determines the error, or the difference between 
// the correct result (sin(x)) and the incorrect result (sin_(x))
float error_(float input_angle)
{
	float error;

	// Error = Correct - Measured
	// Correct = sin(input_angle)
	// Measured = sin_(input_angle)
	error = sin(input_angle) - sin_(input_angle);

	return error;
}

// This function builds a lookup table that stores the sin for all values between 0 and 359 degrees using a taylor series.
void init()
{
	
	// need to somehow combine lookup table creation and lookup table population (using the same shit as float sin_)
	const int lookup_table[360] =
}


// This is the main function that executes all the other functions to produce desired output.
int main (void)
{
	// Creation and population of lookup table.
	init();

	float input_angle;
	printf("Enter an angle: \n");
	scanf("%f", &input_angle);

	printf("%f %f %f %f", input_angle, sin(input_angle), sin_(input_angle), error_(input_angle));

	return 0;
}