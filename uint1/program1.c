//create an arrayof size 10, input values,print the array,and search an element.
#include<stdio.h>
#include<conio.h>
void main()
{
    int a[10],i,search,found=0;
    printf("enter 10 elements:\n");
    for (i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n array elements are:\n ");
    for(i=0;i<10;i++)
     {
        printf("%d ", a[i]);
    }

    printf("\n\nEnter element to search: ");
    scanf("%d", &search);

    for(i=0; i<10; i++)
    {
        if(a[i] == search)
        {
            found = 1;
            printf("Element found at position %d", i + 1);
            break;
        }
    }

    if(found == 0)
        printf("Element not found.");

    getch();
}

