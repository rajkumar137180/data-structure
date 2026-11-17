#include<stdio.h>

int main(){
    int tree[7]={50,30,70};
    int i, count = 0;

    for(i =0;i<7;i++)
    if(tree[i] != 0)
        count++;

    printf("Total Nodes = %d",count);

    return 0;
}
