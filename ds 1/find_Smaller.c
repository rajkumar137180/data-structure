//Write a program to find the smallest common Divisor of Given number.
#include <stdio.h>

int main()
{
      int a, b, i, min;

      printf("Enter two number:");
      scanf("%d%d", &a, &b);


      min = (a < b) ? a : b;

      for(i = 2; i <= min; i++)
      {
          if(a % i ==0 && b % i == 0)
          {
             printf("Smallest Common Divisor = %d", i);
            return 0;
          }
      }
     printf("No common divisor other than 1.");

    return 0;

}
