#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int *next;
} NODE;

int* array_from_input(){
    int i, size;
    int *v;
    scanf("%d", &size);
    v = malloc(size * sizeof(int));
    for(i=0; i < size; i++){
        scanf("%d", &v[i]);
    }
    
    return v;
}

int* ll_from_input(){
    int i,size;
    scanf("%d", &size);
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

int* createll(int arr[],int n){
    int i;
    NODE *first,*current,*previous;
    first=(NODE *) malloc(sizeof(NODE));
    first->data=arr[0];
    first->next=NULL;
    
    previous=first;
    for (i=1;i<n;i++){
        current=(NODE *) malloc(sizeof(NODE));
        current->data=arr[i];
        current->next=NULL;
        previous->next= current;
        previous=current;
    }
    return first;
}
void displayll(NODE *p){
    if (p!=NULL){
        printf("%d ",p->data);
        displayll(p->next);
    }
    
}

void main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int *a;
    a=createll(arr,10);
    displayll(a);
}


