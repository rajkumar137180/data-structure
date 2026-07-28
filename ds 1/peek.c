#include<stdio.h>
//#include<conio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
  if (top == MAX-1)
   printf("\nStack overflow");
  else
 {
    top++;
    stack[top] = value;
  }
}
 void Peek()
{
  if(top == -1)
     printf("\nStack underflow");
   else
    printf("\nTop Element = %d", stack[top]);
}

 void main()
{
  //clrscr();

  push(10);
  push(20);
  push(30);

  Peek();

getch();
}








