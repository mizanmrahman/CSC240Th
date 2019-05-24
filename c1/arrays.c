#include<stdio.h>

int main(void) {

  /* Initializing array declarations */
  int a[4] = {1, 2, 3, 4};
  double b[3] = {2.4, 3.14, 9.9999};
  char c[5] = {'H', 'e', 'l', 'l', 'o'};
  char d[] = "world";    /* No size given - initialized to the size of "world" */
                         /* Note that strings all null-terminated (a '\0' at the end
                             so d is 6 elements, not 5 */
  char e[] = {65, 66, 67, 68, 69, 70}; /* e is the size of the intializer */
  /* What happens if we declare an array with a size smaller than the initializer? */

  unsigned int ii;

  /* What happens when we go past the end of the array? */
  for (ii=0;ii<6;ii++) {
    printf("a[%d]=%d (%x)\n", ii, a[ii], a[ii]);
  }
  printf("\n");

  /* Are these sizes what you expect ? */
  printf("Size of a=%lu\n", sizeof(a));   
  printf("Size of int=%lu\n", sizeof(int));   
  printf("\n");

  /* what does (sizeof(a)/sizeof(int) do? */
  for (ii=0;ii<(sizeof(a)/sizeof(int));ii++) {
    printf("a[%d]=%d (%x)\n", ii, a[ii], a[ii]);
  }
  printf("\n\n");

  /* This loop intentionally goes one character too far */
  for(ii=0;ii<6;ii++) {
     printf("c[%d]=%c (%d)\td[%d]=%c (%d)\n", 
             ii, c[ii], c[ii], ii, d[ii], d[ii]);
  }
  printf("\n");

  printf("Size of c=%lu, c=%s\n", sizeof(c), c);   
  printf("Size of d=%lu, d=%s\n", sizeof(d), d);   
  printf("\n");

  /* Is the following allowed? */
  d[5]=88;
  d[6]=88;
  d[7]=88;
  printf("d after modifying d[5]-d[7]: d size=%lu, d=%s\n", sizeof(d), d);   
  printf("\n");

  /* Notice how many items print */
  printf("More trouble with c\n");
  for(ii=5;ii<16;ii++) {
    c[ii] = 88;
  }
  printf("Size of c=%lu, c=%s\n", sizeof(c), c);   
  printf("Size of d=%lu, d=%s\n", sizeof(d), d);   
  printf("\n");

  return 0;
}
