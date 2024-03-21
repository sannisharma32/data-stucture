//WAP to perform basic operations (traversing, inserting, deleting, reversing //
//and display) on array. //

#include <stdio.h>

void traverseArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size, int index, int element) {
    if (index < 0 || index > *size) {
        printf("Invalid index\n");
        return;
    }
    
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = element;
    (*size)++;
}

void deleteElement(int arr[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid index\n");
        return;
    }
    
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i+1];
    }
    (*size)--;
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;

    traverseArray(arr, size);
    insertElement(arr, &size, 2, 6);
    deleteElement(arr, &size, 3);
    reverseArray(arr, size);
    displayArray(arr, size);

    return 0;
}
