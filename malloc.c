#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr;
    int n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    ptr = (int*) malloc(n * sizeof(int));
   
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    else
    {
        printf("Memory allocation successful.\n");
        
        for (i = 0; i < n; ++i)
        {
            ptr[i] = i + 1;
        }
        
        printf("Elements of the array: ");
        
        for (i = 0; i < n; ++i)
        {
            printf("%d ", ptr[i]);
        }
    }
    
    free(ptr); // Free allocated memory
    
    return 0;
}
