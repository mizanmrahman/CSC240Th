#include<stdio.h>

int main(void) {

  int num = 6;  /* integer */
  int * ptr;    /* pointer to an integer (or integer pointer) */

  /* & : reference operator - returns the address */
  /* * : dereference operator - returns an alias */

  ptr = &num;
  printf("num = %d, %p, %lu\n", num, (void *) &num, sizeof(num));
  printf("ptr = %p, %p, %lu, *ptr=%d\n", (void *) ptr, (void *) &ptr, sizeof(ptr), *ptr);

  /* *ptr is an alias of num */
  *ptr = 20;
  printf("\n*ptr=20\n");
  printf("num = %d, %p, %lu\n", num, (void *) &num, sizeof(num));
  printf("ptr = %p, %p, %lu, *ptr=%d\n", (void *) ptr, (void *) &ptr, sizeof(ptr), *ptr);
  
  printf("ptr:\n");
  printf("ptr = %p\n", (void *) ptr); 
  printf("*ptr = %d\n", *ptr); 
  printf("*(&ptr) = %p\n", (void *) *(&ptr)); 
  printf("&(*ptr) = %p\n", (void *) &(*ptr)); 

  printf("num:\n");
  printf("num = %d\n", num); 
  printf("&num = %p\n", (void *) &num); 
  printf("*(&num) = %d\n", *(&num)); 
  /* COMPILE ERROR: printf("&(*num) = %p\n", (void *) &(*num));  */

  return 0;
}
