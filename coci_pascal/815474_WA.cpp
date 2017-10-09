#include<stdio.h>
int isPrime(int M) {
	int i;
	for(i=2;i*i<=M;i++) {
		if(M%i==0) return 0;
	}
	return 1;
}
int main() {
	int N;
	scanf("%d",&N);
	int i;
	if(N==1 || isPrime(N)) {
		printf("0");
		return 0;
	}
	for(i=2;i*i<=N;i++) {
		if(N%i==0) {
			//N/i
			int c=N/i;
			printf("%d",N-N/i);
			break;
		}
	}
}