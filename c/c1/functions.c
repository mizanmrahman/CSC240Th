#include<stdio.h>

/* Forward declaration - what happens if we remove these? */
void say_hello();
int add_ten(int);
void add_twenty(int *);
int add_array(int[], int);

int main(void) {

  int a = 5;
  int b = 0;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

  printf("a=%d, b=%d\n", a, b);
  printf("add_ten(a)=%d, add_ten(b)=%d\n", add_ten(a), add_ten(b));
  printf("a=%d, b=%d\n", a, b);
  printf("add_twenty(&b)\n");
  add_twenty(&b);
  printf("a=%d, b=%d\n", a, b);
  printf("add_ten(a)=%d, add_ten(b)=%d\n", add_ten(a), add_ten(b));
  printf("a=%d, b=%d\n", a, b);

  printf("\n\nadd_array(arr, 8) = %d\n", add_array(arr, 8));


  say_hello();

  return 0;
}

void say_hello() {
  printf("Hello!\n");
}

/* Call by Value: Returns a value, does not modify x */
int add_ten(int x) {
  return x + 10;
}

/* Call by Address: Modifies x, does not return a value */
void add_twenty(int *x) {
  *x = *x + 20;
}

/* Since the array length is unknown, we ned to pass the length as well */
int add_array(int a[], int len) {
  int ii;
  int sum = 0;
  for(ii=0;ii<len;ii++) {
    sum += a[ii];
  }
  return sum;
}
