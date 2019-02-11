#include <stdio.h> 
 // in this example an HVAC system is controlled by 
 // a control word  -> control word???
 // Bit 0      FAN ON/OFF 
 // Bit 1      VENT OPEN/CLOSED 
 // Bit 2      COMPRESSOR ON/OFF 
 // Bit 3-12   DESIRED TEMP 
#define  ALL_OFF        0x0000 
#define  FAN_ON         0x0001 
#define  FAN_OFF        ~FAN_ON // negate FAN_ON
#define  VENT_OPEN      0x0002 
#define  VENT_CLOSED    ~VENT_OPEN // negate VENT_OPEN
#define  COMPRESSOR_ON  0x0004 
#define  COMPRESSOR_OFF ~COMPRESSOR_ON // negate COMPRESSOR_ON
#define  TEMP_MASK      0x0ff8 

// temp_mask in binary is 111111111000
// so the 0-2 (from the right) are for fan/vent/compressor
// and the bits 3-12 (from the right) are for temperature

// %x is printf format that indicates int value should be displayed as a hexidecimal

#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

const char *b2b_(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

unsigned short int hvac_control = ALL_OFF; 
int main(int argc,char* argv[])  
{ 
    
	printf("Size of hvac_control is: %zu\n", sizeof(hvac_control));
    // all off 
    hvac_control = ALL_OFF;
    unsigned short int hvac_control1 = ALL_OFF;

    printf("HVAC_CONTROL  : %s\n", b2b_(hvac_control));
    printf("ALL OFF       : %s\n", b2b_(hvac_control)); 
    printf("FAN_ON        : %s\n", b2b_(FAN_ON));
    printf("FAN_OFF       : %s\n", b2b_(FAN_OFF));
    printf("VENT_OPEN     : %s\n", b2b_(VENT_OPEN));
    printf("VENT_CLOSED   : %s\n", b2b_(VENT_CLOSED));
    printf("COMPRESSOR_ON : %s\n", b2b_(COMPRESSOR_ON));
    printf("COMPRESSOR_OFF: %s\n", b2b_(COMPRESSOR_OFF));
    printf("TEMP_MASK     : %s\n", b2b_(TEMP_MASK));

    printf("All Off: %04x\n\n",hvac_control); 

    // open the vent 
    printf("Opening the vent\n");
    hvac_control |= VENT_OPEN; 
    printf("Vent Open: %04x\n",hvac_control); 

    printf("ALL_OFF (Hex)      = %04x\n", ALL_OFF);
    printf("VENT_OPEN (Hex)    = %04x\n", VENT_OPEN);
    printf("hvac_control (Hex) = %04x\n", hvac_control);
    printf("hvac_control (Dec) = %d\n", hvac_control);
    printf("hvac_control (04Hex) = %04x\n", hvac_control);
    printf("hvac_control (04Dec) = %d\n\n", hvac_control);

    // turn on the compressor and the fan  
    // at the same time (while vent is open)
    printf("Turning on compressor and fan while vent is open\n");
    hvac_control |= ( FAN_ON | COMPRESSOR_ON );
    printf("hvac_control (Starting Out)            : %04x\n", hvac_control1);
    printf("FAN_ON                                 : %04x\n", FAN_ON);
    printf("COMPRESSOR_ON                          : %04x\n", COMPRESSOR_ON);
    printf("FAN_ON AND COMPRESSOR_ON               : %04x\n", ( FAN_ON | COMPRESSOR_ON ));
    printf("VENT_OPEN                              : %04x\n", VENT_OPEN);
    printf("hvac_control given VENT_OPEN           : %04x\n", hvac_control1 | VENT_OPEN);
    printf("hvac_control AND Fan AND Compressor On : %04x\n", hvac_control); 

    printf("hvac_control (Hex) = %x\n", hvac_control);
    printf("hvac_control (Dec) = %d\n", hvac_control);
    printf("hvac_control (04Hex) = %04x\n", hvac_control);
    printf("hvac_control (04Dec) = %04d\n\n", hvac_control);

    //  set the temp 
    printf("Setting the temperature\n");
    unsigned int temp = 3; 
    unsigned int tempMain;
    unsigned int temp0, temp1, temp2, temp3, temp4;
    temp0 = temp << 0;
    temp1 = temp << 1;
    temp2 = temp << 2;
    temp3 = temp << 3;
    temp4 = temp << 4;
    printf("temp (Not Left Shifted)         : %d\n", temp);
    printf("temp (Left Shifted by 0)        : %d\n", temp0);
    printf("temp (Left Shifted by 1)        : %d\n", temp1);
    printf("temp (Left Shifted by 2)        : %d\n", temp2);
    printf("temp (Left Shifted by 3)        : %d\n", temp3);
    printf("temp (Left Shifted by 4)        : %d\n", temp4);
    tempMain = temp << 4;  
    printf("tempMain                        : %d\n", tempMain);
    printf("TEMP_MASK                       : %d\n", TEMP_MASK);
    tempMain &= TEMP_MASK; // limits the bits that can be set 
    printf("tempMain &= TEMP_MASK)          : %d\n", tempMain);
    printf("tempMain = tempMain & TEMP_MASK : %d\n", tempMain & TEMP_MASK);
    hvac_control = hvac_control | tempMain; 
    printf("%04x\n",hvac_control); 

    printf("hvac_control (Hex) = %x\n", hvac_control);
    printf("hvac_control (Dec) = %d\n", hvac_control);
    printf("hvac_control (04Hex) = %04x\n", hvac_control);
    printf("hvac_control (04Dec) = %04d\n\n", hvac_control);


    //  turn the compressor off 
    printf("Turning the compressor off\n");
    hvac_control &= ( FAN_OFF ); 
    printf("%04x\n",hvac_control); 

    printf("hvac_control (Hex) = %x\n", hvac_control);
    printf("hvac_control (Dec) = %d\n", hvac_control);
    printf("hvac_control (04Hex) = %04x\n", hvac_control);
    printf("hvac_control (04Dec) = %04d\n\n", hvac_control);
}    
