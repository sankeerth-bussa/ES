#include <LPC214x.h>
int main() {
char a[10];
unsigned int z;
PINSEL0 =0x00000005;
U0LCR=0x83;
U0DLM=0x00;
U0DLL=0x61;
U0LCR=0x03;
while(1)
for(z=0;z<10;z++) {
while(!(U0LSR&0x01));
a[z]=U0RBR;
while(!(U0LSR&0x20));
U0THR=a[z];
}
}
