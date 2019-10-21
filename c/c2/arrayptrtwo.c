#include <stdio.h>

int main()
{
    int A[3][3]={
	 { 1, 2, 3},
	 { 4, 5, 6},
	 { 7, 8, 9}
    };

    /* Address of elements in an array */
    printf("%d ", A);
    printf("%d ", *A);
    printf("%d ", *(A+0));

    printf("\n");
    printf("%d ", A+1);
    printf("%d ", *(A+1));
   
    printf("\n");
    printf("%d ", A+2);
    printf("%d ", *(A+2));
    
    
    printf("\n \n");
    printf("%d ", *(A+0)+0);
    printf("%d ", *(A+0)+1);
    printf("%d ", *(A+0)+2);


    printf("\n");
    printf("%d ", *(A+1)+0);
    printf("%d ", *(A+1)+1);
    printf("%d ", *(A+1)+2);


    printf("\n");
    printf("%d ", *(A+2)+0);
    printf("%d ", *(A+2)+1);
    printf("%d ", *(A+2)+2);
    
    
    /* Accessing the elements of Array */
    printf("\n \n");
//    printf("%d ", **A);
//    printf("%d ", *(*A));
//    printf("%d ", *(*(A+0)));
    printf("%d ", *(*(A+0)+0));
    printf("%d ", *(*(A+0)+1));
    printf("%d ", *(*(A+0)+2));
    
       
    printf("\n");
//    printf("%d ", *(*(A+1)));
    printf("%d ", *(*(A+1)+0));
    printf("%d ", *(*(A+1)+1));
    printf("%d ", *(*(A+1)+2));

    
    printf("\n");
//    printf("%d ", *(*(A+2)));
    printf("%d ", *(*(A+2)+0));
    printf("%d ", *(*(A+2)+1));
    printf("%d ", *(*(A+2)+2));


    printf("\n \n");

// pointer ptr pointing at array num
  int *ptr = &A[0][0];
  
  // other variables
  int TOTAL_CELLS = (3 * 3),
    i;

  // print the elements of the array num via pointer ptr
  for (i = 0; i < TOTAL_CELLS; i++) {
    printf("%d ", *(ptr + i));
  }

  // print the elements of the array num via pointer ptr
  for (i = 0; i < TOTAL_CELLS; i++) {
    printf("%d ", (ptr + i));
  }

    return 0;
}
