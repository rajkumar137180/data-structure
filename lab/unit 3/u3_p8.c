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

void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
    } else {
        *head = temp->next;
        (*head)->prev = NULL;
    }
    printf("Successfully deleted first node (%d)\n", temp->data);
    free(temp);
}

void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        printf("Successfully deleted last node (%d)\n", temp->data);
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    printf("Successfully deleted last node (%d)\n", temp->data);
    free(temp);
}

void deleteSpecific(struct Node** head, int target) {
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

    if (curr == *head) {
        deleteFirst(head);
        return;
    }

    if (curr->next == NULL) {
        deleteLast(head);
        return;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    printf("Successfully deleted specific node (%d)\n", curr->data);
    free(curr);
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
    append(&head, 40);

    printf("--- Initial List ---\n");
    display(head);
    printf("\n");

    printf("--- Operation A: Delete First Node ---\n");
    deleteFirst(&head);
    display(head);
    printf("\n");

    printf("--- Operation B: Delete Last Node ---\n");
    deleteLast(&head);
    display(head);
    printf("\n");

    append(&head, 25);
    append(&head, 35);
    printf("--- List after appending 25 and 35 ---\n");
    display(head);
    printf("\n");

    printf("--- Operation C: Delete Specific Node (25) ---\n");
    deleteSpecific(&head, 25);
    display(head);

    return 0;
}
