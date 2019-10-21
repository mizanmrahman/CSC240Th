#include <stdio.h>

int main(void) {
  char str1[] = "Hello";   /* string (null-terminated character array) */
  char str2[] = {'W', 'o', 'r', 'l', 'd'}; /* character array (not a string!) */
  char str3[] = {'e', 'n', 'd', '\0'}; /* null-terminated char array (a string!) */
  int ii;

  printf("\nOriginal str2:\n");
  for(ii=0;ii<20;ii++) {
    printf("str2[%d]=%c (%d)\n", ii, str2[ii], str2[ii]);
  }

  printf("str1: %s \t %lu\n", str1, sizeof(str1));
  printf("str2: %s \t %lu\n", str2, sizeof(str2));
  printf("str3: %s \t %lu\n", str3, sizeof(str3));


  for(ii=1;ii<40;ii++) {
    printf("[%c]  ", str3[ii]);
    if (ii % 10 == 0) {
      printf("\n");
    }
  }
  printf("\n");
  return 0;
}
