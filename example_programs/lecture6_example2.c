#include <stdio.h> 
 
int main(int argc,char* argv[]) 
{ 
    float a; 
    float b; 
 
    a = 0.0; 
    for (int i=0;i<500;i++) 
        a = a + 0.112; 
        b = 0.112 * 500.0; 

    if (a==b) 
        printf("they are equal %f %f\n",a,b); 
    else 
        printf("they are not equal %f %f\n",a,b); 
    return 0; 
}
