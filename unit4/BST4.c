#include<stdio.h>

int main(){
    int tree[7]={50,30,70};
    int height = 0;

    if(tree[0] != 0)
        height = 1;
    if(tree[1] != 0 || tree[2] != 0)
        height = 2;
    if(tree[3] != 0 || tree[4] != 0 || tree[5] != 0 || tree[6] !=0)
        height = 3;
    printf("Height = %d", height);

    return 0;

}

