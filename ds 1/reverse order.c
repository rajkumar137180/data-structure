//Write a program to print strings in reverse order using stack.
#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if(top == MAX-1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

char pop()
{
    if(top == -1)
    {
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

void main()
{
    char str[MAX];
    int i;

    //clrscr();

    printf("Enter a string: ");
    gets(str);

    /* Push all characters into stack */
    for(i = 0; str[i] != '\0'; i++)
    {
        push(str[i]);
    }

    printf("\nReversed String: ");

    /* Pop all characters from stack */
    while(top != -1)
    {
        printf("%c", pop());
    }

    getch();
}
