#include<stdio.h>
int N,M;
struct A {
	int S,E,T,C;
}H[10000];
int Sum=0;
int main() {
	scanf("%d%d",&M,&N);
	int i,j;
	for(i=1;i<=N;i++) scanf("%d%d%d%d",&H[i].S,&H[i].E,&H[i].T,&H[i].C);
	for(i=1;i<=M;i++) {
		int winner=0;
		int time=99999999;
		for(j=1;j<=N;j++) {
			if(time > H[j].T && H[j].S <= i && H[j].E >= i) {
				winner=j;
				time = H[j].T;
			}
		}
		Sum+=H[winner].C;
	}
	printf("%d",Sum);
}