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
PORTC=0b00000001;
int x,y,z,xl,yl,zl;
x=0;
y=0;
z=0;
xl=255;
yl=255;
zl=255;
int k;
while(1)
{

LCDClear();

LCDWriteString("x=");
LCDWriteInt(x,3);
LCDWriteString("y=");
LCDWriteInt(y,3);
LCDWriteString("z=");
LCDWriteInt(z,3);
LCDGotoXY(0,1);

LCDWriteString("x=");
LCDWriteInt(xl,3);
LCDWriteString("y=");
LCDWriteInt(yl,3);
LCDWriteString("z=");
LCDWriteInt(zl,3);

k=5;
while(k)
{if (getdata(0)>x)
	  {
  		x=getdata(0);
	  }
 if (getdata(1)>y)
 	{
		y=getdata(1);
	}
 if (getdata(2)>z)
 	{
		z=getdata(2);
	}
 if (getdata(0)<xl)
 	{
		xl=getdata(0);
	}
 if (getdata(1)<yl)
 	{
		yl=getdata(1);
	}
 if (getdata(2)<zl)
  	{
		zl=getdata(2);
	}
	k--;
}
}
}

