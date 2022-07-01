#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} NODE;

NODE *head;
NODE *rear;

int dequeue(){
    NODE *temp=head->next;
    int x=head->data;
    free(head);
    head=temp;
    return x;
}

void enqueue(int x){
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    if (head!=NULL){
        temp->data=x;
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
    else{
        temp->data=x;
        temp->next=NULL;
        head=temp;
        rear=temp;

    }

}

int main() {
    int x,size,i;
    head=NULL;
    rear=NULL;
    printf("Enter size\n");
    scanf("%d",&size);
    for (i=0;i<size;i++){
        printf("Input\n");
        scanf("%d",&x);
        enqueue(i);
    }
    for (i=0;i<size;i++){
        
        printf("%d",dequeue());
    }
    
    
    return 0;
}