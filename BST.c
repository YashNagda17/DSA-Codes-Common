#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *root;

NODE * CreateNode(int x){
    NODE *newn;
    newn=(NODE *)malloc(sizeof(NODE));
    newn->data=x;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}

void insertnode(int x){
    NODE *temp,*ptr;
    temp=ptr=root;
    while (temp!=NULL){
        ptr=temp;
        if (x>temp->data){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    if (x>ptr->data){
        ptr->right=CreateNode(x);
    }
    else{
        ptr->left=CreateNode(x);
    }
}




int search(int x,int y){
    int tp;
    NODE *temp=root;
    while (temp!=NULL){
        tp=temp->data;
        if (((x<=tp)&&(y>tp))||((y<=tp)&&(x>tp))){
            return tp;
        }
        else if (tp<x){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }}
    printf("Key does not exist");
    return -100;
}

int lowest(NODE *ptr){
    while ((ptr->left)!=NULL){
        ptr=ptr->left;
    }
    return ptr->data;
}

int highest(NODE *ptr){
    while ((ptr->right)!=NULL){
        ptr=ptr->right;
    }
    return ptr->data;
}

void prereversal(NODE *ptr){
     if (ptr!=NULL){
     printf("%d ",ptr->data);
     prereversal(ptr->left);
     prereversal(ptr->right);   
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
    root=NULL;
    
    int size,inp,i,j;
    scanf("%d",&size);
    scanf("%d",&inp);
    root=CreateNode(inp);
    for (i=1;i<size;i++){
        scanf("%d",&j);
        insertnode(j);
    }
    inorder(root);
    
    
    return 0;
}