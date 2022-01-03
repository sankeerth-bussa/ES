#include "lcd.h"
#include "type.h"
#include "types.h"
U8 init_sdcard(void)
{
if(if_initInterface(0)==0)
return 1;
else
return 0;
}
void test_sd_card(void)
{
if(init_sdcard())
{
lcd_clear();
lcd_putstring(LINE1,"SD card - OK");
}
else
{
lcd_clear();
lcd_putstring(LINE1,"SD card - not OK");
}
}

int main (void)
{
euint8 write_buffer[16] = {'S', 'D', 'C', 'A', 'R', 'D', 'T', 'E', 'S', 'T', 'P', 'A', 'S', 'S',0};
euint8 read_buffer[16];
init_lcd();
test_sd_card();
delay(3000*200);
while (1)
{
if (!sd_writeSector(0, write_buffer)) // write into SD CARD
lcd_putstring(1,"Memory WR error ");
if (!sd_readSector(0, read_buffer,16)) // read from SD CARD
lcd_putstring(1,"Memory RD error ");
lcd_clear();
lcd_putstring(0," Read Data is: ");
lcd_putstring(1,(char *)read_buffer);
delay(5000*5000);
}
}
