#include <stdio.h>

int main()
{
    int A[3]={1, 2, 3};

    /* Address of elements in an array */
    printf("%d ", A);
    printf("%d ", A+1);
    printf("%d ", A+2);
    
    printf("\n");
    printf("%d ", *A);
    printf("%d ", *(A+0));
    printf("%d ", *(A+1));
    printf("%d ", *(A+2));

 
    printf("\n");
   int *ptr = A;
   
   printf("Value of first element is %d", *ptr);  
     
    printf("\n");
   // sizof(int) * (number of element in A[]) is printed 
   printf("Size of A[] %d\n", sizeof(A)); 
  
   // sizeof a pointer is printed which is same for all type  
   // of pointers (char *, void *, etc) 
   printf("Size of ptr %d", sizeof(ptr)); 

    printf("\n");
   printf("A[2] = %d\n", A[2]); 
   printf("*(A + 2) = %d\n", *(A + 2)); 
   printf("ptr[2] = %d\n", ptr[2]); 
   printf("*(ptr + 2) = %d\n", *(ptr + 2)); 


  return 0; 
}
