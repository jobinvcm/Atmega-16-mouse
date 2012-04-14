#include <avr/io.h>
#include <util/delay.h>
#include "lcd.c"
void main()
{
InitLCD(LS_ULINE);
LCDWriteString("Hello World");
}

