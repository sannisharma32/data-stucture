#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the circular linked list
void traverseCircularLinkedList(struct Node* head) {
    printf("Circular Linked List: ");
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    
    printf("\n");
}

// Function to insert a node at the beginning of the circular linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        
        newNode->next = *head;
        current->next = newNode;
        *head = newNode;
    }
    
    printf("Inserted %d at the beginning.\n", data);
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("Circular linked list is empty. Cannot delete.\n");
        return;
    }
    
    struct Node* current = *head;
    struct Node* prev = NULL;
    
    // If the node to be deleted is the only node
    if (current->data == data && current->next == *head) {
        free(current);
        *head = NULL;
        printf("Deleted %d from the circular linked list.\n", data);
        return;
    }
    
    // If the node to be deleted is the first node
    if (current->data == data) {
        while (current->next != *head) {
            current = current->next;
        }
        
        current->next = (*head)->next;
        free(*head);
        *head = current->next;
        printf("Deleted %d from the circular linked list.\n", data);
        return;
    }
    
    // Traverse the circular linked list to find the node to be deleted
    do {
        prev = current;
        current = current->next;
    } while (current != *head && current->data != data);
    
    // If the node is not found
    if (current == *head) {
        printf("%d not found in the circular linked list.\n", data);
        return;
    }
    
    // Delete the node
    prev->next = current->next;
    free(current);
    printf("Deleted %d from the circular linked list.\n", data);
}

// Function to create a circular linked list
struct Node* createCircularLinkedList(int values[], int length) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 0; i < length; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = values[i];
        
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}

// Main function
int main() {
    // Create a circular linked list
    int values[] = { 1, 2, 3, 4, 5 };
    int length = sizeof(values) / sizeof(values[0]);
    struct Node* head = createCircularLinkedList(values, length);
    
    // Traverse and print the circular linked list
    traverseCircularLinkedList(head);
    
    // Insert a node at the beginning
    insertNode(&head, 0);
    traverseCircularLinkedList(head);
    
    // Delete a node
    deleteNode(&head, 3);
    traverseCircularLinkedList(head);
    
    // Free memory
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
        
        if (current == head)
            break;
    }
    
    return 0;
}
