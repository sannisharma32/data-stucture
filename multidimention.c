#include <stdio.h>
int main()
{
    int arr[3][3], i, j;
    printf("Enter the elements of the array \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }
    printf("all element in arry \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}