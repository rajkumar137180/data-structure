#include<stdio.h>

int main(){
    int tree[7]={50,30,70};
    int x = 70,i;

    for(i = 0;i<7;i++)
        if(tree[i] == x)
        tree[i] = 0;
        printf("Tree: ");

    for(i = 0;i < 7;i++)
        if(tree[i] !=0)
            printf("%d ",tree[i]);

    return 0;
}
