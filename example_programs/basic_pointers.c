#include <stdio.h> 
int main(int argc,char *argv[]) 
{ 
    int count=2; 
    int* countptr= &count; 
    printf("%d\n",*countptr); 
    return 0; 
}

// 2
