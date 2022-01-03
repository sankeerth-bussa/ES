#include "mbed.h"
#include "rtos.h"
DigitalOut led1(LED1);
DigitalOut led2(LED2);
Serial pc(USBTX, USBRX); // tx, rx
Thread *(test);
void led2_thread(void const *args) {
while (true) {
led2 = !led2;
Thread::wait(1000);
}
}
int main() {
Thread thread(led2_thread);
test = &thread;
test->set_priority(osPriorityHigh);
pc.printf("%i\n\r",test->get_priority());
while (true) {
led1 = !led1;
Thread::wait(500);
}
}
