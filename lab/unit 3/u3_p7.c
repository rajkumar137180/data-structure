#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(struct Node* head, int target, int val) {
    struct Node* curr = head;
    while (curr != NULL && curr->data != target) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Target node %d not found!\n", target);
        return;
    }

    struct Node* newNode = createNode(val);
    newNode->next = curr->next;
    newNode->prev = curr;

    if (curr->next != NULL) {
        curr->next->prev = newNode;
    }
    curr->next = newNode;
    printf("Successfully inserted %d after %d\n", val, target);
}

void insertBefore(struct Node** head, int target, int val) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* curr = *head;
    while (curr != NULL && curr->data != target) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Target node %d not found!\n", target);
        return;
    }

    struct Node* newNode = createNode(val);

    if (curr == *head) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else {
        struct Node* prevNode = curr->prev;
        newNode->next = curr;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        curr->prev = newNode;
    }
    printf("Successfully inserted %d before %d\n", val, target);
}

void display(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    printf("--- Initial List ---\n");
    display(head);
    printf("\n");

    printf("--- Operation A: Insert After ---\n");
    insertAfter(head, 20, 25);
    display(head);
    printf("\n");

    printf("--- Operation B: Insert Before (Middle) ---\n");
    insertBefore(&head, 25, 22);
    display(head);
    printf("\n");

    printf("--- Operation B: Insert Before (Head) ---\n");
    insertBefore(&head, 10, 5);
    display(head);

    return 0;
}
