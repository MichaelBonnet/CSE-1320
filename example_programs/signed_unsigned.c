#include <stdio.h>

// this code snippet shows 
// the difference between signed 
// and unsigned is
// only interpretation, not 
// the representation in memory

int main(int argc,char* argv[])
{
  // the interpretation is done by printf() 
  // based upon the descriptor
  printf("%d %u %x %d \n", -5, -5, -5, -5);
/*
 * -5 4294967291 fffffffb -5
 */

  unsigned int UI;
  signed int SI;

  SI = -5;
  UI = 4294967291;

  SI = SI + 1;
  UI = UI + 1;

  // add one to either variable,
  // the answer is the same
  printf("%d %u %x  %d %u %x\n",SI,SI,SI,UI,UI,UI);
  return 0;
}
