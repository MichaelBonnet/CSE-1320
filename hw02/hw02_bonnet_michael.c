#include <stdio.h>
#include <assert.h>
#include <math.h>
#define LUT_LEN (360)
#define PI 3.14159265358979323846


float lookup_table[LUT_LEN];


int fact(int factorial_quantity)
{
    int fact = 1;

    for (int i = 1; i <= factorial_quantity; i++)
    {
        fact *= i;
    }

    return fact;
}

float deg_to_rad(float input_angle)
{

    float deg_to_rad = input_angle * (PI/180);

    return deg_to_rad;
}

float taylorseries_(float input_angle)
{
    float x, sine;

    x = input_angle;

    sine = x - pow(x,3)/fact(3) + pow(x,5)/fact(5)
             - pow(x,7)/fact(7);

    return sine;
}


void init(void)
{
    int tempx;

    for(size_t i = 0; i < 91; i++)
    {
        lookup_table[i] = taylorseries_(deg_to_rad(i));
    }

    for(size_t i = 91; i < 181; i++)
    {
        tempx = 180 - i;
        lookup_table[i] = lookup_table[tempx];
    }

    for(size_t i = 181; i < 360; i++)
    {
        tempx = i - 180;
        lookup_table[i] = (-1) * lookup_table[tempx];
    }
}


float interpolation(float x0, float y0, float x1, float y1, float x)
{
    float interpolation = y0 + (x - x0) * ( (y1 - y0)/(x1 - x0) );

    return interpolation;
}

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

float error_(float input_angle)
{   
    float error_ = sin(deg_to_rad(input_angle)) - sin_(input_angle);

    return error_;
}


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
