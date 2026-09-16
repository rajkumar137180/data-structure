#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


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


struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}


struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty. Deletion not possible.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

struct Node* deleteLastNode(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty. Deletion not possible.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }


    free(temp->next);
    temp->next = NULL;

    return head;
}

struct Node* deleteSpecificNode(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return NULL;
    }

    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }


    if (current == NULL) {
        printf("Value %d not found in the list.\n", value);
        return head;
    }

    prev->next = current->next;
    free(current);
    return head;
}

int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    printf("Original List:\n");
    displayList(head);

    printf("\nAfter deleting the first node (10):\n");
    head = deleteFirstNode(head);
    displayList(head);


    printf("\nAfter deleting the last node (50):\n");
    head = deleteLastNode(head);
    displayList(head);

    printf("\nAfter deleting specific node with value 30:\n");
    head = deleteSpecificNode(head, 30);
    displayList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
