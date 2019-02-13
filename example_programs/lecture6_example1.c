#include <stdio.h> 
int main(int argc,char* argv[]) 
{ 
    // lets look at the bit pattern of a float 
    union 
    { 
       float f; 
       int   i; 
    } u; 
    // a union makes f and i share the same memory location 
    u.f = 2.0; 
    printf(" %f %x\n",u.f,u.i); 
    u.f = 4.0; 
    printf(" %f %x\n",u.f,u.i); 
    u.f = 8.0; 
    printf(" %f %x\n",u.f,u.i); 
    u.i = 0x41800000; 
    printf(" %f %x\n",u.f,u.i); 
    return 0; 
} 
