#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int size;
    int keys[100];
    struct node *children[50];
    int leaf;
} NODE;


int searchBT(int k,NODE *x){
    int i=0;
    while ((i<(x->size))&&(k>((x->keys)[i]))){
        i++;
    }
    if ((i<(x->size))&&(k==((x->keys)[i]))){
        return 1;
    }
    else if (x->leaf){
        return 0;
    }
    else{
        return searchBT(k,x->children[k]);
    }   
}

NODE *createbtree(int x){
    NODE *newn;
    int i;
    newn=(NODE *)malloc(sizeof(NODE));
    newn->keys[0]=x;
    newn->size=1;
    newn->leaf=1;
    for (i=0;i<50;i++){
        newn->children[i]=NULL;
    }
    return newn;
}




int main(){

    return 0;
}