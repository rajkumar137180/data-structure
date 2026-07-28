write a c program to display the top element of the stack without removing it.
#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Peek operation
void peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    peek();

    return 0;
}
