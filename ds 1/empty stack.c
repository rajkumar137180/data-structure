write a c program to check weather the stack is empty
#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    if (top == -1)
        return 1;   // Stack is empty
    else
        return 0;   // Stack is not empty
}

int main() {
    if (isEmpty())
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");

    // Push an element
    stack[++top] = 10;

    if (isEmpty())
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");

    return 0;
}
