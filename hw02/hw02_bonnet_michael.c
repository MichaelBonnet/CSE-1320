#include <stdio.h>
#include <assert.h>
#define PI (3.14159265358979323846)
#include <math.h>


float lookup_table[360];


// The purpose of the following function is to return the factorial of the passed argument.
// The following function achieves this by incrementing i from 1 up to and including the int value
// of the passed argument, and then multiplying each of the incremented values of i together
// to get the factorial.
// This is done in the background and requires no user activity.
int fact(int factorial_quantity)
{
    int fact = 1;

    for (int i = 1; i <= factorial_quantity; i++)
    {
        fact *= i;
    }

    return fact;
}

// The purpose of the following function is to convert the passed argument, 
// a quantity of degrees, to radians.
// The following function achieves this by multiplying the degree quantity
// by the quantity (PI/180), as PI radians is equal to 180 degrees.
// This is done in the background to convert user input to a usable unit
// and requires no user activity.
float deg_to_rad(float input_angle)
{

    float deg_to_rad = input_angle * (PI/180);

    return deg_to_rad;
}

// The purpose of the following function is to determine the sum of 
// a Taylor Series of the sine of the quantity of radians derived from
// user input in units of degrees to the 4th term (not including the first term x).
// The following function achieves this through summing the first 4 terms of the taylor series sequentially.
// This function happens in the background and requires no user interaction.
float taylorseries_(float input_angle)
{
    float x, sine;

    x = input_angle;

    sine = x - pow(x,3)/fact(3) + pow(x,5)/fact(5)
             - pow(x,7)/fact(7);

    assert(sine <= 1.0);  // This assert statement checks that the value of sine is within the normal period of sine from the right, from -1 to 1.
    assert(sine >= -1.0); // This assert statement checks that the value of sine is within the normal period of sine from the left, from -1 to 1.

    return sine;
}


// The purpose of the following function is to populate the global variable
// lookup table with roughly accurate results of sine(x) for x >= 0 and x < 360.
// The following function achieves this through using a Taylor Series to accurately
// populate the domain up to 90 degrees, and then uses unit circle rules to populate
// the remaining 3/4 of the domain.
// This function happens in the background and requires no user interaction.

//  // This assert() checks that the quantity equal to PI is in fact mathematical pi.

void init(void)
{
    assert(PI == 3.14159265358979323846); // This assert checks to make certain I have the proper value of pi.

    int supplement;
    int explement;

    for(size_t i = 0; i < 91; i++)
    {
        lookup_table[i] = taylorseries_(deg_to_rad(i));
    }

    for(size_t i = 91; i < 181; i++)
    {
        supplement = 180 - i;
        lookup_table[i] = lookup_table[supplement];
    }

    for(size_t i = 181; i < 360; i++)
    {
        explement = i - 180;
        lookup_table[i] = (-1) * lookup_table[explement];
    }
}


// The purpose of the following function is to linearly interpolate between two (x, y) ordered pairs.
// The following function achieves this through implementing the basic linear interpoplation equation.
// This function happens in the background and requires no user interaction.
float interpolation(float x0, float y0, float x1, float y1, float x)
{
    float interpolation = y0 + (x - x0) * ( (y1 - y0)/(x1 - x0) );

    return interpolation;
}

// The purpose of the following function is to determine the proper x-values, and therefore y-values,
// of the two ordered pairs (x0, y0) and (x1, y1) to be used in linear interpolation in order to find
// a more exact value for the sine of a noninteger degree quantity between 0 and 359 degrees.
// The following function achieves this through assigning a float (the quantity) to an int, truncating it
// and therefore rounding it to the proper x0 value. The proper x(1) value is determined by adding 1 to x0;
// the other necessary terms are derived from these two quantities and the input angle.
// This function also performs input validation by automaticaly returning a 0.0 for inputs outside the intended domain.
// This function happens in the background and requires no user interaction.
float sin_(float input_angle)
{
    float result;
    int lowest_x_value = input_angle;
    int highest_x_value = lowest_x_value + 1;

    if (input_angle < 0 || input_angle >= 360)
    {
        return 0.0;
    }

    if (lowest_x_value == input_angle)
    {
        return lookup_table[lowest_x_value];
    }

    result = interpolation(lowest_x_value, lookup_table[lowest_x_value], highest_x_value, lookup_table[highest_x_value], input_angle);

    return result;
}

// The purpose of the following function is to find the error, or difference,
// between the "true" sine value and the sine value calculated through interpolation and Taylor Series.
// The following function achieves this by subtracting the result of sin_, the interpolation value,
// from the "true" sine value.
// This function happens in the background and requires no user interaction.
float error_(float input_angle)
{   
    float error_ = sin(deg_to_rad(input_angle)) - sin_(input_angle);

    return error_;
}


// The purpose of the following function is to execute all functions and logic to produce the desired outcome.
// This is generally the purpose of functions called 'main'.
// This main function works by calling init() to populate an array of sine values,
// then prompting the user for a degree quantity to return values for.
// by doing the prompting within a do-while loop, it is always executed at least once, and keeps going
// until the user exits the program via typing -1 when prompted for input.
int main (void)
{
    init();

    float input_angle;

    do
    {

        printf("Enter an angle in degrees, where 0 <= angle < 360: \n");
        scanf("%f", &input_angle);

        if (input_angle == -1)
        {
            return 0;
        }
            else
            {
                printf("%f %f %f %f\n", input_angle, sin_(input_angle), sin(deg_to_rad(input_angle)), error_(input_angle));
            }

    } while (input_angle != -1);

    return 0;
}
