#include <LPC214X.H>
#include <Stdio.h>
#include "Type.h"
#include "lcd.h"
#include "I2C.h"
#include "TIMER.h"

int main(void)
{
uint8 write_buffer[16] = {'E', 'E', 'P', 'R', 'O', 'M', 'T', 'E', 'S', 'T', 'P', 'A', 'S', 'S',0};
uint8 read_buffer[16];
init_lcd();
I2C_Init();
TIMER_Init();
lcd_putstring(0," ES LAB ");
lcd_putstring(1,"I2C EEPROM Demo ");
delay(3000*500);
while(1)
{
if (!I2C_WriteToEEPROM(0, write_buffer, 16)) 
lcd_putstring(1,"Memory WR error ");
if (!I2C_ReadFromEEPROM(0, read_buffer, 16)) 
lcd_putstring(1,"Memory RD error ");
lcd_clear();
lcd_putstring(0," Read Data is: ");
lcd_putstring(1,(char *)read_buffer);
delay(5000*5000);
}
}
