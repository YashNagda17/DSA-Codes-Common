#include <stdio.h>
#include <stdlib.h>

int arr[1000];

int maximum(int a,int b,int c){
    if (((arr[a])>=(arr[b]))&&((arr[a])>=(arr[c]))){
        return a;
    }
    else if (((arr[b])>=(arr[a]))&&((arr[b])>=(arr[c]))){
        return b;
    }
    return c;
}

void maxheapify(int index,int size){
    int largest,l,r,k;
    if ((2*index+1)>=size){
        return;
    }
    else{
        l=2*index+1;
    }
    if ((2*index+2)>=size){
        r=l;
    }
    else{
        r=2*index+2;
    }
    largest=maximum(index,l,r);
    
    if (largest==index){
        return;
    }
    else{
        while (((largest)<size)&&(arr[largest]>arr[index])){
            k=arr[index];
            arr[index]=arr[largest];
            arr[largest]=k;
            l=largest*2+1;
            index=largest;
            r=largest*2+2;
            if (r>=size){
                r=l;
            }
            largest=maximum(index,l,r);                           
        }
        
    }
}

int minimum(int a,int b,int c){
    if (arr[b]==0){
        return a;
    }
    if (arr[c]==0){
        if (arr[b]<arr[a]){
            return b;
        }
        else{
            return a;
        }

    }
    if (((arr[a])<=(arr[b]))&&((arr[a])<=(arr[c]))){
        return a;
    }
    else if (((arr[b])<=(arr[a]))&&((arr[b])<=(arr[c]))){
        return b;
    }
    return c;
}

void minheapify(int index,int size){
    int largest,l,r,k;
    if ((2*index+1)>=size){
        return;
    }
    else{
        l=2*index+1;
    }
    if ((2*index+2)>=size){
        r=l;
    }
    else{
        r=2*index+2;
    }
    largest=minimum(index,l,r);
    
    if (largest==index){
        return;
    }
    else{
        while (((largest)<size)&&(arr[largest]<arr[index])){
            k=arr[index];
            arr[index]=arr[largest];
            arr[largest]=k;
            l=largest*2+1;
            index=largest;
            r=largest*2+2;
            if (r>=size){
                r=l;
            }
            largest=minimum(index,l,r);                           
        }
        
    }


}

int deletion(int size){
    int x,y;
    x=arr[0];
    size--;
    arr[0]=arr[size];
    y=size/2;
    while (y>-1){
        heapify(y,size);
        y--;
    }  
    return x;
}


int main(){
    int i,j,size;
    scanf("%d",&size);
    for (i=0;i<size;i++){
        scanf("%d",&j);
        arr[i]=j;
    }
    for (i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    i=size/2;
    i--;
    while (i>-1){
        heapify(i,size);
        i--;
    }
    for (i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}