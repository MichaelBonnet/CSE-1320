#include <stdio.h> 
#include <assert.h> 
#define ARRAY_DEBUG 
#define N 25 
float lut[N] = {0.0}; 
#ifdef ARRAY_DEBUG 
void set_lut(float val,int i) 
{ 
   assert(i>=0 && i<N); 
   lut[i] = val; 
} 
float get_lut(int i) 
{ 
   assert(i>=0 && i<N); 
   return lut[i]; 
} 
#else 
#define set_lut(A,B)  lut[B]=A 
#define get_lut(A)    lut[A]    
#endif 
int main(int argc,char *argv[]) 
{ 
   set_lut(234.0,1); 
   printf("%f\n",get_lut(1)); 
   printf("%f\n",get_lut(N)); 
   return 0; 
}
