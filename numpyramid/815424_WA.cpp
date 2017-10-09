#include<stdio.h>
#define MOD 1000000009
int N,M;
int C[100][100];
int D[100][1000011];
int main() {
	scanf("%d%d",&N,&M);
	int i,j;
	if(N>=21 || N>M) return 0;
	C[1][1]=1;
	for(i=2;i<=N;i++) {
		for(j=1;j<=i;j++) C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
	}
	int sum=1;
	for(i=1;i<=M;i++) D[1][i]=1;
	for(i=2;i<=N;i++) {
		sum+=C[N][i];
		for(j=sum;j<=M;j++) D[i][j] = (D[i-1][j-C[N][i]]+D[i][j-1])%MOD;
	}
	printf("%d",D[N][M]);
}