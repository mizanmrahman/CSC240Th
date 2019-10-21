#include<stdio.h>
#include"mystuff.h"

/* To compile:
     gcc -ansi -pedantic -Wall multifile.c mystuff.c
*/

int main(void) {
  printf("Multifile example:\n");
  printf("Max1: %d\n", MAX(20, 13));
  printf("Max2: %d\n", MAX(NUM, 13));
  printf("Max3: %d\n", max_of_three(20, 13, NUM));
  return 0;
}
