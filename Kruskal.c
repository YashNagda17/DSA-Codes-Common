#include <stdio.h>
#include <stdlib.h>





int main(){
    int v,e,a,b,min1,min2,i,w,j;
    scanf("%d",&v);
    scanf("%d",&e);
    int min=10000;
    int cost=0;
    int graph[100][100]={0};
    int mst[100][100]={0};
                              //0th column =0 not gone yet, 1 == visited.
    for (i=0;i<e;i++){
        scanf("%d",&a);
        scanf("%d",&b);
        a++;
        b++;
        scanf("%d",&w);
        graph[b][a]=w;
        graph[a][b]=w;
        if (w<min){
            min=w;
            min1=a;
            min2=b;
        }
    }
    
    
    int size=1;
    while (size<v){
        mst[min1][min2]=mst[min2][min1]=min;
        mst[min1][0]=mst[min2][0]=1;
        cost+=min;
        min=10000;
        size++;
        for (i=1;i<=v;i++){
            if (mst[i][0]==1){
                for (j=1;j<=v;j++){
                    if ((graph[i][j]!=0)&&(mst[j][0]==0)){
                        if (graph[i][j]<min){
                            min=graph[i][j];
                            min1=i;
                            min2=j;
                        }
                    }

                }
            }
        }
    }
    if (cost<10000){
        printf("%d",cost);
    }
    else{
        printf("-1");
    }
    return 0;
      


    }

    

