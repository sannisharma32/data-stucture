#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the linked list
void traverseLinkedList(struct Node* head) {
    printf("Linked List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the first node
    if (current->data == data) {
        *head = current->next;
        free(current);
        printf("Deleted %d from the linked list.\n", data);
        return;
    }

    // Traverse the linked list to find the node to be deleted
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    // If the node is not found
    if (current == NULL) {
        printf("%d not found in the linked list.\n", data);
        return;
    }

    // Delete the node
    prev->next = current->next;
    free(current);
    printf("Deleted %d from the linked list.\n", data);
}

// Function to create a linked list
struct Node* createLinkedList(int values[], int length) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 0; i < length; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = values[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Main function
int main() {
    // Create a linked list
    int values[] = { 1, 2, 3, 4, 5 };
    int length = sizeof(values) / sizeof(values[0]);
    struct Node* head = createLinkedList(values, length);

    // Traverse and print the linked list
    traverseLinkedList(head);

    // Insert a node at the beginning
    insertNode(&head, 0);
    traverseLinkedList(head);

    // Delete a node
    deleteNode(&head, 3);
    traverseLinkedList(head);

    // Free memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
