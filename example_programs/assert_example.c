#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

float area (float h, float w)
{
    // area is always positive
    // so we refuse to continue 
    // if that is not the case
    assert (h>0.0);
    assert (w>0.0);
    return h*w;
}

#define N (5)

int main(int argc,char* argv[])
{
   float thermostat_temp[N] = {72.0,70.0,70.0,69.0,78.0};

   // for test data
   float biggest_delta_temp = 0.0;
   // not the simplest algorithm, but it shows using loops
   // ( alternate, find the min() and the max() and subtract)
   for (int i=0;i<N;i++)
   {
      for (int j=i;j<N;j++)
      {
         if (abs(thermostat_temp[i]-thermostat_temp[j])> abs(biggest_delta_temp))
         {
             biggest_delta_temp = thermostat_temp[i]-thermostat_temp[j];
         }
      }
   }
   printf("largest delta %f\n",biggest_delta_temp);
}
