#include<stdio.h>
int hap[5000001];
int N,T;
int main() {
	int i;
	int d;
	scanf("%d",&N);
	for(i=1;i<=N-1;i++) {
		scanf("%d",&hap[i+1]);
		hap[i+1] = hap[i]+hap[i+1];
	}
	scanf("%d",&T);
	int a,b;
	for(i=1;i<=T;i++) {
		scanf("%d%d",&a,&b);
		printf("%d\n",hap[b]-hap[a]);
	}
}