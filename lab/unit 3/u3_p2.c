#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;

    newNode->next = head;

    head = newNode;

    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }


    newNode->data = value;
    newNode->next = NULL;


    if (head == NULL) {
        head = newNode;
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    printf("Initial empty list:\n");
    displayList(head);


    printf("\nInserting 10, then 20 at the starting:\n");
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    displayList(head);


    printf("\nInserting 30, then 40 at the end:\n");
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    displayList(head);


    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
