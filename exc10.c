#include <stdio.h>
#include <stdlib.h>

int queue[100], n, size, rear = -1, front = -1;

void enqueue() {
    if (rear == -1 && front == -1) {
        front = 0;
        rear = 0;
        printf("Enter element: ");
        scanf("%d", &n);
        queue[rear] = n;
    } else if ((rear + 1) % size == front) {
        printf("Queue is full.\n");
    } else {
        rear = (rear + 1) % size;
        printf("Enter element: ");
        scanf("%d", &n);
        queue[rear] = n;
    }
}

void dequeue() {
    if (rear == -1 && front == -1) {
        printf("Queue is empty.\n");
    } else if (rear == front) {
        rear = -1;
        front = -1;
    } else {
        front = (front + 1) % size;
    }
}

void display() {
    if (rear == -1 && front == -1) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % size;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice;
    printf("Enter size of queue: ");
    scanf("%d", &size);

    while (choice != 4) {
        printf("\n1. Enqueue an element\n2. Dequeue element\n3. Display the queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Enter valid choice.\n");
        }
    }

    return 0;
}
