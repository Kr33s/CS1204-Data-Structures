    #include <stdio.h> 



    int main()
    {
        int i, j;  
        int tempholder; //  let tempholder be a temporary variable 
        int a[8];  
        for (i=0;i<8;i++)
        { // for loop to take input from the user     
            printf("Number: "); //Here we enter the numbers to be sorted 
            scanf("%d", &a[i]);
        } 
        for (i=0;i<7;i++) // This is outer loop where we will compare the numbers 
        {
            for (j=i+1;j<8;j++) // This is inner loop where we will compare the numbers 
            {
                if (a[i]>a[j])
                tempholder=a[i]; 
                a[i]=a[j]; 
                a[j]=tempholder; 
                
            }
        }
        printf("Sorted array: "); 
        for (i=0;i<8;i++) 
        {  // for loop to print the sorted array      
            printf("%d ",a[i]); 
        }
    }
        
