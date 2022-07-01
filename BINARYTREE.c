#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}NODE;

typedef struct queue{
    NODE *ptrdta;
    struct queue *next;
}QUEUE;

QUEUE *head,*rear;
NODE *root;

NODE *dequeue(){
    QUEUE *temp=head->next;
    NODE *x=head->ptrdta;
    head=temp;
    return x;
}

void enqueue(NODE *x){
    QUEUE *temp;
    temp=(QUEUE *)malloc(sizeof(QUEUE));
    if (head!=NULL){
        temp->ptrdta=x;
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
    else{
        temp->ptrdta=x;
        temp->next=NULL;
        head=temp;
        rear=temp;
    }
}

NODE *CreateNode(int x){
    NODE *newn;
    newn=(NODE *)malloc(sizeof(NODE));
    newn->data=x;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}

void createtree(int size){
    int i=1,inp;
    NODE *temp;
    while (i<size){
        
        temp=dequeue();
        scanf("%d",&inp);
        temp->left=CreateNode(inp);
        i++;
        if (i>=size){break;}
        enqueue(temp->left);
        scanf("%d",&inp);
        temp->right=CreateNode(inp);
        enqueue(temp->right);
        i++;
    }
}

void inorder(NODE *ptr){
    if (ptr!=NULL){
     
     inorder(ptr->left);
     printf("%d ",ptr->data);
     inorder(ptr->right);   
     
    }

}




int main(){
    rear=head=NULL;
    root=NULL;
    int size,inp;
    scanf("%d",&size);
    scanf("%d",&inp);
    root=CreateNode(inp);
    enqueue(root);
    createtree(size);
    printf("\n");
    inorder(root);



    return 0;
}