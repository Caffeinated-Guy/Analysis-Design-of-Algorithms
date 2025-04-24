#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j,k,source;
    int w[50][50];
    int visited[20];
    int minWt,totalcost=0,sv=0,ev=0;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter the weight/cost matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&w[i][j]);
        }
    }
    printf("enter the source vertex to start: \n");
    scanf("%d",&source);
    for(i=1;i<=n;i++){
        visited[i]=0;
    }
        visited[source]=1;
        printf("minimum weight/cost edges selected for spanning tree are:\n");
        for(i=1;i<n;i++){
            minWt=999;
            for(j=1;j<=n;j++){
                if(visited[j]==1){
                    for(k=1;k<=n;k++){
                        if(visited[k]!=1 && w[j][k]<minWt){
                            sv=j;
                            ev=k;
                            minWt=w[j][k];
                        }
                    }
                }
            }
            totalcost += minWt;
            visited[ev] = 1;
            printf("%d--> %d--cost: %d\n",sv,ev,minWt);
        }
        printf("total cost of minimum spannning tree is: %d\n",totalcost);
    return 0;
    }
    