//Write a program to find the power of a given number using stack.

#include<stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push (int value)
{

  if(top == MAX - 1)
  {
      printf("Stack overflow\n");
      return;
  }
   stack[++top] = value;

}

int pop()
{
    if (top == -1)
    {
         printf("Stack Underflow\n");
         return -1;
    }
    return stack[top--];
}

int main()
{

    int base, exponent, result = 1, i;

    printf("Enter Base: ");
    scanf("%d", &base);

    printf("Enter Exponent: ");
    scanf("%d", &exponent);

    for(i = 0; i < exponent; i++)
       push(base);

       while(top != -1)
        result *= pop();

   printf("%d^%d = %d\n", base, exponent, result);

   return 0;
}
