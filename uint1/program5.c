//Program 5: Find the Largest Element in an Array
#include<stdio.h>
void main()
{
    int a[10], i, largest;

    printf("Enter 10 elements:\n");
    for(i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }

    largest = a[0];

    for(i=1; i<10; i++)
    {
        if(a[i] > largest)
            largest = a[i];
    }

    printf("\nLargest element = %d", largest);
}
