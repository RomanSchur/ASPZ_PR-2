#include <stdio.h>
#include <stdint.h>
#include <time.h>
int main() {
  time_t max_32 = INT32_MAX;
  printf("Максимальне значення time_t для 32-х бітної системи: %ld\n", (long)max_32);
   
  time_t max_64 = INT64_MAX;
  printf("Максимальне значення time_t для 64-х бітної системи: %lld\n", (long long)max_64);

  return 0;
}