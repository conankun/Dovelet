#include<stdio.h>
int main() {
	int N,A[100];
	int i,j;
	scanf("%d",&N);
	for(i=1;i<=N;i++) scanf("%d",&A[i]);
	int cnt=0;
	for(i=1;i<=N;i++) {
		for(j=i+1;j<=N;j++) {
			if(A[j]%A[i]==0) cnt++;
		}
	}
	printf("%d",cnt);
}