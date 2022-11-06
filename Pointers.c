#include <stdio.h>
#include <stdlib.h>

void main()
{   
    //Trying the calloc function in a dynamic array in C. This will assign zero to all spaces
    printf("CALLOC TESTING\n");
    int c, n, i;

    //User input for number of elements
    printf("Enter value of n: ");
    scanf("%d", &c);

    //Dynamically allocate memory using calloc()
    int* ctr = (int*)calloc(c,sizeof(int));

    //printing default values after calloc is carried out
    for(i =0; i<c; ++i)
    {
        printf("Value: %d \n", ctr[i]);
    }

    //Trying the malloc function in dynamic array in C
    printf("MALLOC TESTING\n");
 
    // User input to get a fixed size of array
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
 
    // Dynamically allocate memory using malloc()
    int* pointer = (int*)malloc(n * sizeof(int));
    
    //storing values in the array, can be done by user, here:- we are storing i*3
    for (i = 0; i< n; i++)
    {
        pointer[i] = i*3;
    }
    
    //printing that address and array elements
    printf("Address: %p \n", pointer);
    for (i=0; i<n; i++)
    {
        printf("Value: %d \n", pointer[i]);
    }

    printf("TESTING FREE\n");
    //malloc and calloc functions have alredy been carried out we will be checking the results of the memory adress before and after using free

    if(pointer != NULL)
    {
        printf("Memory Present Post Malloc\n");
        printf("Address: %p \n", pointer);
        //using free
        free(pointer);
        printf("Memory has been freed\n");
    }
    else
    {
        printf("Memory is already empty\n");
    }

    if(ctr != NULL)
    {
        printf("Memory Present Post Calloc\n");
        printf("Address: %p \n", ctr);
        //using free
        free(ctr);
        printf("Memory has been freed\n");  
    }
    else
    {
        printf("Memory is alredy empty\n");
    }
}