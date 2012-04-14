#include <avr/io.h>
#include <util/delay.h>
#include "lcd.c"
#include "adc.h"
void main()
{
DDRC=0xff;
InitLCD(LS_ULINE);
LCDWriteString("Hello World");
adc_init();
PORTC=0x00;
while(1)
{

_delay_ms(1000);
LCDClear();

LCDWriteString("x=");
LCDWriteInt(getdata(0),4);

LCDWriteString("y=");
LCDWriteInt(getdata(1),4);


LCDWriteString("z=");
LCDWriteInt(getdata(2),4);
}
}

