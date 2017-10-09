#include<stdio.h>
int n;
int floodfill[101][101];
int main(){
scanf("%d",&n);
int k,i,j;
for(k=1;k<=n;k++) {
int a,b;
scanf("%d%d",&a,&b);
for(i=a;i<a+10;i++) {
for(j=b;j<b+10;j++) {
floodfill[i][j]=1;
}
}
}
int sum=0;
for(i=1;i<=100;i++) {
for(j=1;j<=100;j++) {
if(!floodfill[i+1][j]) sum+=floodfill[i][j];
if(!floodfill[i-1][j]) sum+=floodfill[i][j];
if(!floodfill[i][j+1]) sum+=floodfill[i][j];
if(!floodfill[i][j-1]) sum+=floodfill[i][j];
}
}
printf("%d",sum);
}