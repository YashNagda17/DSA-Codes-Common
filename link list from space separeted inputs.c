#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} NODE;
NODE* ll_from_input(int size){
    int i;
    
    NODE *first,*current,*previous;
    first=(NODE *) malloc(sizeof(NODE));
    scanf("%d", &(first->data));
    
    first->next=NULL;
    
    previous=first;
    for (i=1;i<size;i++){
        current=(NODE *) malloc(sizeof(NODE));
        scanf("%d", &(current->data));
        
        current->next=NULL;
        previous->next= current;
        previous=current;
    }
    return first;
}

void displayll(NODE *p){
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    
}
int main() {
    int size;
    NODE *a;
    scanf("%d", &size);
    a=ll_from_input(size);
    displayll(a);
    return 0;
}