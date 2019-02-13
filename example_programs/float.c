#include <stdio.h>
#include <float.h>

int main(int argc,char* argv[])
{
   printf("float %ld\n",sizeof(float));
   printf("double %ld\n",sizeof(double));
   printf("long double %ld\n",sizeof(long double));

   printf(" Number of significant digits for\n float %d\n double %d\n long double %d\n",FLT_DIG,DBL_DIG,LDBL_DIG);


   float        f = 123.456789f;  // f or F
   double       d = 123.4567890123;
   long double ld = 123.456789012345l; // l or L
   printf(" %f\n %lf\n  %Lf\n",f,d,ld);

   // show them in memory
   int* ptr;
   ptr = (int*) &f;
   printf("float\n");
   printf("%p %x\n",ptr,*ptr);

   ptr = (int*) &d;
   printf("double\n");
   printf("%p %08x\n",ptr,*ptr);
   ptr++;
   printf("%p %08x\n",ptr,*ptr);
   
   ptr = (int*) &ld;
   printf("long double\n");
   printf("%p %08x\n",ptr,*ptr);
   ptr++;
   printf("%p %08x\n",ptr,*ptr);
   ptr++;
   printf("%p %08x\n",ptr,*ptr);
   ptr++;
   printf("%p %08x\n",ptr,*ptr);

   return 0;
}
