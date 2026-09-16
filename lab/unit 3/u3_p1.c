#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;

    if (n <= 0) {
        return NULL;
    }

    for (int i = 1; i <= n; i++) {
     
        newNode = (struct Node*)malloc(sizeof(struct Node));
        
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL; 

       
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
           
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("\nLinked List Elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    head = createList(n);

    displayList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
