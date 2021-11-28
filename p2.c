#include<lpc214x.h>
void delay();
int main () {
PINSEL0=0x00000000;
IO0DIR=0x0000000f;
while (1) {
IO0SET=0x0000000f;
delay();
IO0CLR=0x0000000f;
delay();
}
}
void delay () {
int i,j;
for (i=0;i<1000;i++)
for (j=0;j<1000;j++);
}
