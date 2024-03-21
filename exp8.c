/* WAP to implement stacks of n elements using array and also perform push
and pop operation.*/
#include <stdio.h>
#include <stdlib.h>

int stack[100], choice, n, top = -1, x, i;

void push();
void pop();
void display();

int main()
{
  
    printf("Enter the size of the stack: ");
    scanf("%d", &n);
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");

    while (choice != 4)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

void push()
{
    if (top >= n - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Enter a value: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        printf("\nThe elements in the stack are: ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack is empty\n");
    }
}
