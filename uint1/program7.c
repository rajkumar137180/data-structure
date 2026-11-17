//Program 7: Delete an Element from User-Defined Position

#include<stdio.h>

void main()
{
    int a[20], n, i, pos;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array elements:\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    printf("Enter position to delete (1-%d): ", n);
    scanf("%d",&pos);

    for(i=pos-1; i<n-1; i++)
        a[i]=a[i+1];

    n--;

    printf("\nArray after deletion:\n");
    for(i=0; i<n; i++)
        printf("%d ",a[i]);

}
