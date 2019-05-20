#include<stdio.h>
#include<string.h>

typedef unsigned int num;            /* user-defined type */
typedef enum {false, true} boolean;  /* enumeration type */

/* struct */
struct a_struct {
  int a;
  int b;
};

/* typedef'd struct */
typedef struct {
  int n;
  boolean success;
  char s[16];
} my_struct_t;

/* Union */
typedef union {
  int n;
  boolean success;
  char s[16];
} my_union_t;

int main(void) {
  num x = 10;
  boolean is_it_true = false;
  my_struct_t myStruct = {10, true, "Hello!"}; 
  struct a_struct myStruct2 = {100, 50};
  struct {int x; int y} myStruct3 = {40, 41}; 
  my_union_t myUnion;
  my_struct_t * ptr;
  

  printf("x=%d [%p]\n", x, (void *) &x);
  printf("is_it_true=%d [%p]\n", is_it_true, (void *) &is_it_true);
  is_it_true = true;
  printf("is_it_true=%d [%p]\n", is_it_true, (void *) &is_it_true);
  if (is_it_true == true) {
    printf("It's true!\n");
  }
  else {
    printf("It's false\n");
  }

  printf("\nStructs:\n");
  ptr = &myStruct;
  printf("myStruct: %d, %d, %s\n", myStruct.n, myStruct.success, myStruct.s);
  printf("ptr: %d, %d, %s\n", ptr->n, ptr->success, ptr->s);
  printf("myStruct2: %d, %d\n", myStruct2.a, myStruct2.b);
  printf("myStruct3: %d, %d\n", myStruct3.x, myStruct3.y);
 
  printf("\nChange struct through variable:\n"); 
  myStruct.n = 30;
  myStruct.success = false;
  strncpy(myStruct.s, "World!",10);
  printf("  myStruct: %d, %d, %s\n", myStruct.n, myStruct.success, myStruct.s);
  printf("Change struct through ptr:\n"); 
  ptr->n = 50;
  ptr->success = true;
  strncpy(ptr->s, "Goodbye!",10);
  printf("  ptr: %d, %d, %s\n", ptr->n, ptr->success, ptr->s);

  printf("\nUnion:\n");
  myUnion.n=0x44434241;
  printf("myUnion: n=%x, s=%s\n", myUnion.n, myUnion.s);
  strncpy(myUnion.s, "X44434241", 10);
  printf("myUnion: n=%x, s=%s\n", myUnion.n, myUnion.s);

  printf("\nSizes:\n");
  printf("x (num): %ld\n", sizeof(x));
  printf("is_it_true (boolean): %ld\n", sizeof(is_it_true));
  printf("myStruct (my_struct_t): %ld\n", sizeof(myStruct));
  printf("myStruct2 (struct a_struct): %ld\n", sizeof(struct a_struct));
  printf("ptr (my_struct_t *): %ld\n", sizeof(ptr));
  printf("myUnion (my_union_t): %ld\n", sizeof(myUnion));
  return 0;
}
