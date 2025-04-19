#include<stdio.h>
#define MAX 20
void floyd(int n,int d[MAX][MAX],int w[MAX][MAX]){
int i,j,k;
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
d[i][j]=w[i][j];
}
}
for(k=1;k<=n;k++){
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
}
}
printf("All pair shortest path matrix is:\n");
for(i=1;i<=n;i++){
printf("\t%d",i);
}
printf("\n\t-------------------------\n");
for(i=1;i<=n;i++){
printf("%d|\t",i);
for(j=1;j<=n;j++){
printf("%d\t",d[i][j]);
}
printf("\n");
}
}
int min(int a,int b){
return (a<b)?a:b;
}
int main(){
int d[MAX][MAX];
int w[MAX][MAX];
int i,j,n;
printf("enter the number of nodes/vertices:");
scanf("%d",&n);
printf("enter the weight/cost matrix:\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
scanf("%d",&w[i][j]);
}
}
floyd(n,d,w);
return 0;
}
