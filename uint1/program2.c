//Program 2: Create an array of size 10, input values and display sum and average

#include<stdio.h>

void main()
{
    int a[10], i, sum = 0;
    float avg;
    printf("Enter 10 elements:\n");
    for(i=0; i<10; i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }

    avg = sum / 10.0;

    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", avg);

    getch();
}
