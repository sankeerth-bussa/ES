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
while (1) {
for(i=0;i<1024;i++)
DacOut(i);
}
}
void DacInit( void ) {
PINSEL1 |= 0x00080000;
}
void DacOut( unsigned int val ) {
DACR = (val << 6) | (DAC_BIAS<<16);
}
