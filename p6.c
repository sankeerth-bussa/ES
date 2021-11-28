#include <lpc214x.h>
#define PLOCK 0x00000400
#define PWMPRESCALE 60
void initPWM(void);
void initClocks(void);
void setupPLL0(void);
void feedSeq(void);
void connectPLL0(void);
int main(void)
{
initClocks();
initPWM();
while(1)
{
PWMMR1 = 2500;
PWMLER = (1<<1);
}
}
void initPWM(void)
{
PINSEL0 = (1<<1);
PWMPCR = 0x0;
PWMPR = PWMPRESCALE-1;
PWMMR0 = 10000;
PWMMCR = (1<<1);
PWMLER = (1<<1) | (1<<0);
PWMPCR = (1<<9);
PWMTCR = (1<<1);
PWMTCR = (1<<0) | (1<<3);
}
void initClocks(void)
{
setupPLL0();
feedSeq();
connectPLL0();
feedSeq();
VPBDIV = 0x01;
}
void setupPLL0(void)
{
PLL0CON = 0x01;
PLL0CFG = 0x24;
}
void feedSeq(void)
{
PLL0FEED = 0xAA;
PLL0FEED = 0x55;
}
void connectPLL0(void)
{
while( !( PLL0STAT & PLOCK ));
PLL0CON = 0x03;
}
