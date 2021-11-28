#include <LPC214x.h>
#define DESIRED_BAUDRATE 9600
#define CRYSTAL_FREQUENCY_IN_HZ 12000000
#define MAX_PCLK (CRYSTAL_FREQUENCY_IN_HZ*5)
#define PCLK (MAX_PCLK/4)
#define DIVISOR (PCLK/(16*DESIRED_BAUDRATE))
void InitUart0(void);
unsigned char Rx_char(void);
void Tx_char(char );
int Tx_string(char *);
int main() {
PINSEL0=0x05;
InitUart0();
Tx_string("This program will echo characters received\n");
while(1)
Tx_char(Rx_char());
}
void InitUart0(void) {
U0LCR=0x83;
U0DLL=DIVISOR&0xFF;
U0DLM=DIVISOR>>8;
U0LCR=0x03;
U0FCR=0x05;
}
void Tx_char(char ch) {
if(ch=='\n')
{
while(!(U0LSR&0x20));
U0THR='\r';
}
while(!(U0LSR&0x20));
U0THR=ch;
}
int Tx_string(char *s) {
int i=0;
while(s[i]!='\0') {
Tx_char(s[i]);
i++;
}
return(i);
}
unsigned char Rx_char(void) {
char ch;
while(!(U0LSR&0x01));
ch=U0RBR;
return ch;
}
