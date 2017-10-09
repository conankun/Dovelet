#include<stdio.h>
int P[4];
int fill[1000];
int main() {
	scanf("%d%d%d",&P[1],&P[2],&P[3]);
	int i,j;
	for(i=1;i<=3;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		for(j=a+1;j<=b;j++) {
			fill[j]++;
		}
	}
	int sum=0;
	for(i=1;i<1000;i++) sum+=P[fill[i]]*fill[i];
	printf("%d",sum);
}