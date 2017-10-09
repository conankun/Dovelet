#include<stdio.h>
int a,b;
int arr[1000][1000];
int main() {
	scanf("%d%d",&a,&b);
	int i,j;
	for(i=1;i<=a;i++){ arr[i][1]=1;}for(i=1;i<=b;i++) arr[1][i]=1;
	for(i=2;i<=a;i++) {
		for(j=2;j<=b;j++) {
			arr[i][j]=arr[i-1][j]+arr[i][j-1];
		}
	}
	for(i=1;i<=a;i++,printf("\n")) for(j=1;j<=b;j++) printf("%d ",arr[i][j]);
}