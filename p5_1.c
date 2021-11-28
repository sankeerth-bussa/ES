#include <LPC214x.h>
#define DAC_BIAS 0
void DacInit( void );
void DacOut( unsigned int val );
void Delay45Us(void);
int main (void) {
unsigned int i = 0;
DacInit();
IODIR1|=0xFFFF0000;
IOPIN1&=~(0xFFFF0000);
while (1){
i=1023;
DacOut(i);
Delay45Us();
i=0;
DacOut(i);
Delay45Us();
}
}
void Delay45Us(void) {
volatile unsigned int k;
for(k=0;k<409;k++){
__asm
{
nop;
}
}
}
void DacInit( void ){
PINSEL1 |= 0x00080000;
}
void DacOut( unsigned int val ){
DACR = (val << 6) | (DAC_BIAS<<16);
}
