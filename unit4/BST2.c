#include<stdio.h>

int main(){
    int tree[7]={50,30,70};
    int x = 20,i;

    if(x < tree[0]){
        if(x < tree[1])
            tree[3] = x;
        else
            tree[4] = x;
    }else{
        if(x < tree[2])
            tree[5] = x;
        else
            tree[6] = x;
        }
        printf("Tree: ");
        for(i=0;i<7;i++)
            if(tree[i] != 0)
                printf("%d ", tree[i]);
        return 0;
}
