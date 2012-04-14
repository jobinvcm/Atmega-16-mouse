#include <avr/io.h>
#include <util/delay.h>
#include "lcd.c"
#include "adc.h"
void main()
{
InitLCD(LS_ULINE);
LCDWriteString("Hello World");
adc_init();
while(1)
{
_delay_ms(500);
LCDClear();
LCDWriteInt(getdata(0),4);
}
}

