#include <stdio.h>

void swap(int *lhs, int *rhs) {
    int a = *lhs;
    int b = *rhs;

    *rhs = a;
    *lhs = b;
}

int min (int a0, int a1, int a2, int a3, int a4)
{
    // sorting network [[0,1], [2,3], [0,2], [1,3], [2,1], [1,4], [1,2], [0,1], [3,4]]
    // see https://en.wikipedia.org/wiki/Sorting_network#Zero-one_principle
    if (a0 > a1) swap(&a0, &a1);
    if (a2 > a3) swap(&a2, &a3);
    if (a0 > a2) swap(&a0, &a2);
    if (a1 > a3) swap(&a1, &a3);
    if (a2 > a1) swap(&a2, &a1);
    if (a1 > a4) swap(&a1, &a4);
    if (a1 > a2) swap(&a1, &a2);
    if (a0 > a1) swap(&a0, &a1);
    if (a3 > a4) swap(&a3, &a4);

    return a0;
}

int median (int a0, int a1, int a2, int a3, int a4)
{
    // sorting network [[0,1], [2,3], [0,2], [1,3], [2,1], [1,4], [1,2], [0,1], [3,4]]
    // see https://en.wikipedia.org/wiki/Sorting_network#Zero-one_principle
    if (a0 > a1) swap(&a0, &a1);
    if (a2 > a3) swap(&a2, &a3);
    if (a0 > a2) swap(&a0, &a2);
    if (a1 > a3) swap(&a1, &a3);
    if (a2 > a1) swap(&a2, &a1);
    if (a1 > a4) swap(&a1, &a4);
    if (a1 > a2) swap(&a1, &a2);
    if (a0 > a1) swap(&a0, &a1);
    if (a3 > a4) swap(&a3, &a4);

    return a2;
}

int max (int a0, int a1, int a2, int a3, int a4)
{
    // sorting network [[0,1], [2,3], [0,2], [1,3], [2,1], [1,4], [1,2], [0,1], [3,4]]
    // see https://en.wikipedia.org/wiki/Sorting_network#Zero-one_principle
    if (a0 > a1) swap(&a0, &a1);
    if (a2 > a3) swap(&a2, &a3);
    if (a0 > a2) swap(&a0, &a2);
    if (a1 > a3) swap(&a1, &a3);
    if (a2 > a1) swap(&a2, &a1);
    if (a1 > a4) swap(&a1, &a4);
    if (a1 > a2) swap(&a1, &a2);
    if (a0 > a1) swap(&a0, &a1);
    if (a3 > a4) swap(&a3, &a4);

    return a4;
}

int sum (int a0, int a1, int a2, int a3, int a4)
{
	int result;

	result = a0 + a1 + a2 + a3 + a4;

	return result;
}

double mean (int a0, int a1, int a2, int a3, int a4)
{
	double the_sum;
	double result;

	the_sum = a0 + a1 + a2 + a3 + a4;

	result = the_sum / 5.0;
}

int main (void)
{
	int a0, a1, a2, a3, a4;
	int my_min, my_max, my_median, my_sum;
	double my_mean;

	a0 = 25;
	a1 = 5;
	a2 = 0;
	a3 = 0;
	a4 = 2;

	my_min = min(a0, a1, a2, a3, a4);
	my_max = max(a0, a1, a2, a3, a4);
	my_median = median(a0, a1, a2, a3, a4);
	my_sum = sum(a0, a1, a2, a3, a4);
	my_mean = mean(a0, a1, a2, a3, a4);

	printf("%d %d %d %d %d", a0, a1, a2, a3, a4);
	printf("min = %d max = %d median = %d sum = %d mean = %f", min, max, median, sum, mean);
  
  return 0;

}
