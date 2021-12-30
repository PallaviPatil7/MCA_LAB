#include<lpc21xx.h>

void delay(unsigned int c)
{unsigned int a;
for(a=1;a<=60000;a++);}

int main()
{
    PINSEL0=0x00000000;  //Configure P0.0 to P0.15 as GPIO
    PINSEL1=0x00000000;
    PINSEL2=0x00000000;
  IO0DIR|=0xffffffff;		//Setting the direction as output
while(1){ 
		unsigned  long int j;
    int i,a[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
   
   
		for(j=0;j<10;j++)		//10 times rotation
		{ 
				IO0SET=IO0SET|a[j];
				for(i=0;i<10;i++)
				{
				IO0SET= IO0SET|(a[i]<<8);
					 
						delay(100000);			//Delay
						IO0CLR= IO0CLR|(a[i]<<8);		//Clear
				}
				IO0CLR=a[j];
			 
		}
	}
}