#ifndef TASTER_LED_FUNCS_C
#define TASTER_LED_FUNCS_C
#include "./taster_led_funcs.h"
char* read_leds() {
  FILE* fp;
  float percentage;
  long int period = 20000L;
  size_t num_of_bytes = 1;
  char *str;
    fp = fopen("/proc/myled", "r");
    if (fp == NULL) {
      printf("Cannot open /proc/myled for write\n");
      return;
    }
    str = (char*)malloc(sizeof(char));
    getline(&str, &num_of_bytes, fp);
    printf("led value is: %s", str);
    return  str;
}
#endif
