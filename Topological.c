#include<stdio.h>
void readgraph(int n,int a[10][10])
{
int i,j;
for(i=0;i<n;i++){
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}
}
void find_indegree(int n,int a[10][10],int indegree[]){
int i,j,sum;
for(j=0;j<n;j++){
sum=0;
for(i=0;i<n;i++)
sum+=a[i][j];
indegree[j]=sum;
}
}
void topological_sort(int n,int a[10][10])
{
int i,u,v,top,t[10],indegree[10],s[10];
int k=0;
find_indegree(n,a,indegree);
top=-1;
for(i=0;i<n;i++){
if(indegree[i]==0)
s[++top]=i;
}
while(top!=-1){
u=s[top--];
t[k++]=u;
for(v=0;v<n;v++){
if(a[u][v]==1){
indegree[v]--;
if(indegree[v]==0){
s[++top]=v;
}
}
}
}
printf("the topological sort sequence is:");
for(i=0;i<n;i++)
printf("%d",t[i]);
}
void main(){
int n,a[10][10];
printf("\n enter number of values");
scanf("%d",&n);
printf("\n enter the adjacency matrix");
readgraph(n,a);
topological_sort(n,a);
}
