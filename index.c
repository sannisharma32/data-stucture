 #include <stdio.h>

int main()
{
    int i, j, size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter elements of array: ");
    for (i = 0; i < size; i++)
    {
         scanf("%d", &array[i]);
    }

    for (j = 0; j < size; j++)
    {
        printf("The element of array %d is %d\n", j, array[j]);
    }
 
    return 0;
}
