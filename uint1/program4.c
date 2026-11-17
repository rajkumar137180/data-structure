//Program 4 :Create Arrays A, B of Size 3, C of Size 6, and Merge A and B into C

#include<stdio.h>
void main()
{
    int A[3], B[3], C[6];
    int i;
    printf("Enter 3 elements for Array A:\n");
    for(i=0; i<3; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("\nEnter 3 elements for Array B:\n");
    for(i=0; i<3; i++)
    {
        scanf("%d", &B[i]);
    }

    /* Copy Array A into C */
    for(i=0; i<3; i++)
    {
        C[i] = A[i];
    }

    /* Copy Array B into C */
    for(i=0; i<3; i++)
    {
        C[i+3] = B[i];
    }

    printf("\nMerged Array C:\n");
    for(i=0; i<6; i++)
    {
        printf("%d ", C[i]);
    }
}
