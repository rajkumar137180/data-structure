
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
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
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
}

void insertAfter() {
    int key, value;
    struct Node *temp, *newNode;

    printf("Enter the node after which you want to insert: ");
    scanf("%d", &key);

    printf("Enter data for new node: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Specific node not found.\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}

void insertBefore() {
    int key, value;
    struct Node *temp, *prev, *newNode;

    printf("Enter the node before which you want to insert: ");
    scanf("%d", &key);

    printf("Enter data for new node: ");
    scanf("%d", &value);

    if (head != NULL && head->data == key) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = head;
        head = newNode;

        printf("Node inserted successfully.\n");
        return;
    }

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Specific node not found.\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = temp;
    prev->next = newNode;

    printf("Node inserted successfully.\n");
}

void display() {
    struct Node *temp = head;

    printf("Singly Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    create();

    printf("\nOriginal List:\n");
    display();

    printf("\n1. Insert after specific node");
    printf("\n2. Insert before specific node");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        insertAfter();
    }
    else if (choice == 2) {
        insertBefore();
    }
    else {
        printf("Invalid choice.\n");
    }

    printf("\nUpdated List:\n");
    display();

    return 0;
}

