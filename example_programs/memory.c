#include <stdio.h> 
#include <math.h> 
int global_variable; 
int global_variable2; 
void functionA() 
{
}
 
int main(int argc,char* argv[]) 
{ 
    int local_to_main; 
    { 
        int local_inside_scope; 
        { 
            int local_inside_scope2; 
            printf("the address of main %p\n",main); 
            printf("the address of sin %p\n",sin); 
            printf("the address of global_variable %p\n",&global_variable); 
            printf("the address of global_variable2 %p\n",&global_variable2); 
            printf("the address of functionA %p\n",functionA); 
            printf("the address of local_to_main %p\n",&local_to_main); 
            printf("the address of local_inside_scope %p\n",&local_inside_scope); 
            printf("the address of local_inside_scope2 %p\n",&local_inside_scope2); 
        }
    }
    return 0; 
} 
