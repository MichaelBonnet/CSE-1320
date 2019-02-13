#include <stdio.h> 
// in this example an HVAC system is controlled by 
// a control word  
// Bit 0      FAN ON/OFF 
// Bit 1      VENT OPEN/CLOSED 
// Bit 2      COMPRESSOR ON/OFF 
// Bit 3-12   DESIRED TEMP 
#define  ALL_OFF        0x0000 
#define  FAN_ON         0x0001 
#define  FAN_OFF        ~FAN_ON 
#define  VENT_OPEN      0x0002 
#define  VENT_CLOSED    ~VENT_CLOSED 
#define  COMPRESSOR_ON  0x0004 
#define  COMPRESSOR_OFF ~COMPRESSOR_ON 
#define  TEMP_MASK      0x0ff8 
unsigned short int hvac_control = ALL_OFF; 
int main(int argc,char* argv[])  
{ 
    // all off 
    hvac_control = ALL_OFF; 
    printf("%04x\n",hvac_control); 
    // open the vent 
    hvac_control |= VENT_OPEN; 
    printf("%04x\n",hvac_control); 
    // turn on the compressor and the fan  
    // at the same time 
    hvac_control |= ( FAN_ON | COMPRESSOR_ON ); 
    printf("%04x\n",hvac_control); 
    //  set the temp 
    unsigned int temp = 3; 
    temp = temp << 4;  
    temp &= TEMP_MASK; // limits the bits that can be set 
    hvac_control = hvac_control | temp; 
    printf("%04x\n",hvac_control); 
    //  turn the compressor off 
    hvac_control &= ( FAN_OFF ); 
    printf("%04x\n",hvac_control); 
}   
