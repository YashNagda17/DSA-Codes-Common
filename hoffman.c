#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int charac;
    struct NODE *left;
    struct NODE *right;
    struct NODE *parent;
}NODE;

NODE *createnode(int x,int chr){
    NODE *new;
    new=(NODE *)malloc((sizeof(NODE)));
    new->parent=NULL;
    new->left=NULL;
    new->right=NULL; 
    new->data=x;
    new->charac=chr; 
    return new;  
}
void mergearr(int arr[],int start,int mid,int end){
    int i,j,k;
    i=start;
    j=mid;
    k=start;
    
    int crr[200]={0};
    while ((i<(mid))&&(j<end)){
        
        if (arr[i]<=arr[j]){
            crr[k]=arr[i];
            
            i++;
            k++;
        }
        else{
            crr[k]=arr[j];
            
            j++;
            k++;
        }
        
    }
    while (i<(mid)){
        
        
        crr[k]=arr[i];
        
        i++;
        k++;
        
    }
    while (j<end){
        
        
        crr[k]=arr[j];
        
        j++;
        k++;
        
    }
    i=start;
    while (i<(end)){
        arr[i]=crr[i];
        i++;
    }
    
}

void mergesort(int arr[],int start,int end){
    int mid;
    
    
    if ((start<end)&&((start+1)!=end)){
        
        mid=(start+end)/2;
        
        mergesort(arr,start,(mid));
        mergesort(arr,(mid),end);
        mergearr(arr,start,mid,end);
    } 
}

int find(int arr[],int val,int size){
    for (int i=0;i<size;i++){
        if (arr[i]==val){
            return 1;
        }
    }
    return 0;    
}

int main(){
    int diff,size1;
    char str[1000];
    int lst[26]={0};
    scanf("%s",str);
    int final[26]={0};
    int temp[26]={0};
    int i=0;
    while (str[i]!='\0'){
        diff=str[i]-'97';
        lst[diff]++;
        i++;
    }
    int len=i;
    int size=0;
    for (i=0;i<26;i++){
        if (lst[i]!=0){
            final[size]=lst[i];
            temp[size]=lst[i];
            size++;
        }        
    }
    mergesort(temp,0,size);
    
    size1=size;
    for (i=size-1;i>0;i--){
        a=temp[0];
        if (find(lst,a,size)){
            new
        }
        b=temp[1];

        mergesort(temp,0,i);

    }
    return 0;


}