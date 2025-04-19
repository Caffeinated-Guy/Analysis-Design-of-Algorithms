#include<stdio.h>
#define MAX_ITEMS 10
int knapsack(int W,int wt[],int val[],int n){
int i,j;
int v[MAX_ITEMS+1][W+1];
for(i=0;i<=n;i++){
for(j=0;j<=W;j++){
if(i==0||j==0){
v[i][j]=0;
}
else if (j-wt[i]<0){
v[i][j]=v[i-1][j];
}
else{
v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-wt[i]]);
}
}
}
return v[n][W];
}
int max(int a,int b){
return (a>b)?a:b;
}

int main(){
int i;
int W,n,wt[MAX_ITEMS],val[MAX_ITEMS];
printf("enter the number of elements\n");
scanf("%d",&n);
printf("enter the weights\n");
for(i=1;i<=n;i++){
scanf("%d",&wt[i]);
}
printf("enter the values\n");
for(i=1;i<=n;i++){
scanf("%d",&val[i]);
}
printf("enter the maximum weight knapsack \n");
scanf("%d",&W);

printf("the maximum profit %d\n",knapsack( W,wt,val,n));
return 0;
}
