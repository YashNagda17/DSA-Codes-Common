#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *head;

void push(int x){  //element is pushed
    if (head!=NULL){
        NODE *temp;
        temp=(NODE *)malloc(sizeof(NODE));
        temp->data=x;
        temp->next=head;
        head=temp;
    }
    else{
        NODE *temp;
        temp=(NODE *)malloc(sizeof(NODE));
        temp->data=x;
        temp->next=NULL;
        head=temp;
    }
}

int pop(){
    int x=0;  //head value returned
    if (head!=NULL){
        x=head->data;
        NODE *temp=head->next;
        
        free(head);
        head=temp;
        return x;
    }
    else{
        printf("%s\n", "Stack is Empty");
        return 0;
    }
}

int stacktop(){  //gives item head is pointing
    if (head!=NULL){
        return (head->data);
    }
    else {return -1;}
}

int IsEmpty(NODE *ptr){  //check if ptr is empty
    return (ptr==NULL);
}

NODE *create(NODE *ptr){  //create a stack of ptr
    
    ptr=NULL;
    return ptr;
}





int main(){
    int i,j;
    head=create(head);
    for (i=0;i<10;i++){
        push(i);
    }
    for (i=0;i<10;i++){
        j=pop();
        printf("%d\n",j);
    }
      
    
    return 0;
}
