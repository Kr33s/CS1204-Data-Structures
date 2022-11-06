#include <stdio.h>

void printArray(int array[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

void insertion_Sort(int array[], int n)
{
	int a, current, b;
	for (a = 1; a < n; a++) 
	{
		current = array[a];                         //setting current to the next element
		b = a - 1;                              //setting b to the previous element
		while (b >= 0 && array[b] > current)        //while b is greater than 0 and the previous element is greater than the current element
        {           
			array[b + 1] = array[b];                        //move the previous element to the next element
			b = b - 1;                                  //decrement b
		}
		array[b + 1] = current;                 //move the current element to the next element
	}   
}

int main()
{
	int array[] = {543,2,54,732,353,5974,3,63};
	int n = sizeof(array) / sizeof(array[0]);
    printf("Starting array: \n");
    printArray(array, n);
    printf("Final array: \n");
	insertion_Sort(array, n);
	printArray(array, n);

	return 0;
}
