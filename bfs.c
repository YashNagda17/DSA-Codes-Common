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



int check(int arr[],int val,int size){
    int i;
    for (i=0;i<size;i++){
        if (arr[i]==val){
            return 0;
        }
    }
    return 1;
}

void bfs(int graph[][9],int from,int start,int n){
    int i=9;
    int arr[9]={0};
    
    int size=0;
    int x,j;
    enqueue(start);
    while ((size<n)&&(head!=NULL)){
        x=dequeue();
        if (check(arr,x,size)){
            arr[size]=x;
            size++;
            for (j=0;j<i;j++){
                if ((graph[x][j])>0){
                    enqueue(j);
                }
            }
            
        }

    }
    int k=0;
    while (arr[k]!=from){
        k++;
    }
    for (j=k;j<i;j++){
        if ((arr[j]!=0)){
            printf("%d ",arr[j]);
        }
    }



}
int main()
{
    int i;
    scanf("%d",&i);
    int graph[9][9] = {{0, 1, 0, 1, 1, 0, 0, 0, 0},
                   {0, 0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0, 0},
                   {0, 0, 0, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 1, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0, 1, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0, 1},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    bfs(graph,i,i,9);
    
    
    return 0;

}