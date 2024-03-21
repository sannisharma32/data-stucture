#include <stdio.h>

int main()
{
    int arr_size, i, j;
    printf("Enter array size: ");
    scanf("%d", &arr_size);
    int arr[arr_size];
    printf("Enter array elements:\n");
    for (i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("All elements in the array:\n");
    for (i = 0; i < arr_size; i++)
    {
        printf("%d\n", arr[i]);
    }
    for (i = 0; i < arr_size; i++)
    {
        for (j = 0; j < arr_size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Elements in ascending order:\n");
    for (i = 0; i < arr_size; i++)
    {
        printf("%d\n", arr[i]);
    }
    for (i = 0; i < arr_size; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Elements in descending order:\n");
    for (i = 0; i < arr_size; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
