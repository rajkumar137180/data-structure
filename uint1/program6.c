//Program 6: Insert an Element at User-Defined Position
#include<stdio.h>

void main()
{o
    int a[20], n, i, pos, item;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array elements:\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    printf("Enter position to insert (1-%d): ", n+1);
    scanf("%d",&pos);

    printf("Enter element: ");
    scanf("%d",&item);

    for(i=n; i>=pos; i--)
        a[i]=a[i-1];

    a[pos-1]=item;
    n++;

    printf("\nArray after insertion:\n");
    for(i=0; i<n; i++)
        printf("%d ",a[i]);

}
