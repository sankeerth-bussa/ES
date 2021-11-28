#include <stdio.h>
#include <LPC214x.H>
#include "lcd.h"
#define ADC0 0
#define CHANNEL_3 3
void init_adc0( void );
unsigned short adc_read(unsigned char adc_num, unsigned char ch);
void wait(int count) {
int j=0,i=0;
for(j=0;j<count;j++)
for(i=0;i<35;i++);
}
void process_adc(void) {
float vin=0;
unsigned short adc_value = 0;
unsigned char buf[16] = {0};
adc_value = adc_read(ADC0, CHANNEL_3);
sprintf((char *)buf, "ADC:%d ", adc_value);
lcd_putstring(LINE1, (char *)buf);
vin=adc_value*3.3/1023;
sprintf((char *)buf, "vin:%f", vin);
lcd_putstring(LINE2, (char *)buf);
}
int main (void) {
init_adc0();
init_lcd();
wait(100000);
lcd_clear();
while(1) {
process_adc();
wait(30000);
}
}
void init_adc0(void) {
PINSEL1 = (PINSEL1 & ~(3 << 28)) | (1 << 28);
}
unsigned short adc_read(unsigned char adc_num, unsigned char ch) {
unsigned int i=0;
AD0CR = 0x00200D00 | (1<<ch);
AD0CR |= 0x01000000;
do {
i = AD0GDR;
}while ((i & 0x80000000) == 0);
return (i >> 6) & 0x03FF;
}
