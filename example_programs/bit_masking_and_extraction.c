#include <stdio.h> 
int main(int argc,char *argv[]) 
{ 
  unsigned int N = 0xAC123001; 
  unsigned int result; 
  unsigned int MASK = 0xF0000000; 
  result = (N & MASK) >> 28; 
  printf("%d\n",result); 
} 
                     
// 10



// lets do the inverse, and store a ‘7’ in the same locations

// N=0xAC123001


// X=0x00000007

// result = (N & ~MASK) | (X<<28);


// clear out the 0xA and or it with the 7 shifted over
// (note the negation of the MASK, turning F’s into 0’s)




#include <stdio.h> 
int main(int argc,char *argv[]) 
{ 
  unsigned int N    = 0xAC123001; 
  unsigned int MASK = 0xF0000000; 
  unsigned int X    = 0x00000007; 
  unsigned int result = (N & ~MASK) | (X<<28); 
  printf("%x\n",result); 
}
