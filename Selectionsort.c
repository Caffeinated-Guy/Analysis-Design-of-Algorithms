#include<stdio.h>
#include<time.h>
void main(){
int n,i,j,k,t;
//double timetaken;
printf("enter the size of the array\n");
scanf("%d",&n);
int a[n];
srand(time(NULL));
for(i=0;i<n;i++){
a[i]=rand()%1000;
} 

clock_t start=clock();
for(i=0;i<n;i++){
j=i;
for(k=i+1;k<n;k++){
if(a[k]<a[j]){
j=k;
}
}
t=a[i];
a[i]=a[j];
a[j]=t;
}
clock_t end=clock();
double timetaken=((double )(end-start))/CLOCKS_PER_SEC;
printf("time taken %f\n",timetaken);

/*printf("the sorted elements are\n");
for(i=0;i<n;i++){
printf("%d\t",a[i]);
}
printf("\n");*/
}
