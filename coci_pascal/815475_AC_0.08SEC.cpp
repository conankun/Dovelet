#include<stdio.h>
int main() {
	int N;
	scanf("%d",&N);
	int i;
	if(N==1) {
		printf("0");
		return 0;
	}
	for(i=2;i*i<=N;i++) {
		if(N%i==0) {
			//N/i
			int c=N/i;
			printf("%d",N-N/i);
			return 0;
		}
	}
	printf("%d",N-1);
}