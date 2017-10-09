#include<stdio.h>
int N,P;
int K[10000];
int main() {
	scanf("%d%d",&N,&P);
	K[N]=1;
	int B=N;
	for(int i=2;;i++) {
		int C=(B*N)%P;
		B=C;
		if(K[C] != 0) {
			printf("%d",i-K[C]);
			break;
		}
		K[C]=i;
	}
}