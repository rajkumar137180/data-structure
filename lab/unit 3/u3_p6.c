
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    int n, i, value;
    struct Node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void insertAtStart() {
    int value;
    struct Node *newNode;

    printf("Enter data to insert at starting: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    printf("Node inserted at starting successfully.\n");
}

void insertAtEnd() {
    int value;
    struct Node *newNode, *temp;

    printf("Enter data to insert at end: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node inserted at end successfully.\n");
}

void display() {
    struct Node *temp = head;

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    create();

    printf("\nOriginal List:\n");
    display();

    printf("\n1. Insert at Starting");
    printf("\n2. Insert at End");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        insertAtStart();
    }
    else if (choice == 2) {
        insertAtEnd();
    }
    else {
        printf("Invalid choice.\n");
    }

    printf("\nUpdated List:\n");
    display();

    return 0;
}

