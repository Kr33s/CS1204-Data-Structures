#include <stdio.h>
#include <stdlib.h>

void main()
{
    //user input to take size of the array
    int n;
    printf("Number of elements: ");
    scanf("%d", &n);

    //defining an array of size n
    int array[n];

    //user input for array elements
    for(int i = 0; i<n; i++)
    {
        printf("Enter element %d of the array: ", i+1);
        scanf("%d", &array[i]);
    }



    //printing the array
    printf("\nElements in the array: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", array[i]);
    }

    //heapyfying the array
    for(int i = n/2 - 1; i >= 0; i--)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(right < n && array[right] > array[largest])
        {
            largest = right;
        }

        if(left < n && array[left] > array[largest])
        {
            largest = left;
        }

        if(largest != i)
        {
            int tempholder = array[i];
            array[i] = array[largest];
            array[largest] = tempholder;
        }
    }

    //printing the heap
    printf("\nElements in the heap: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", array[i]);
    }

    //sorting the heap
    for(int i = n-1; i >= 0; i--)
    {
        int tempholder = array[0];
        array[0] = array[i];
        array[i] = tempholder;

        int largest = 0;
        int left = 2*largest + 1;
        int right = 2*largest + 2;

        if(left < i && array[left] > array[largest])
        {
            largest = left;
        }
        if(right < i && array[right] > array[largest])
        {
            largest = right;
        }
        if(largest != 0)
        {
            int tempholder = array[0];
            array[0] = array[largest];
            array[largest] = tempholder;
        }
    }

    //printing the sorted heap
    printf("\nElements in the sorted heap: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", array[i]);
    }
}