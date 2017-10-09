#include<stdio.h>
#define MOD 1000000009
unsigned int n,D[5111][5111],T[5111][5111];
int main() {
	scanf("%u",&n);
	unsigned int i,j;
	T[1][1]=1;T[2][1]=1;T[2][2]=2;
	D[1][1]=1;D[2][2]=1;
	for(i=3;i<=n;i++) {
		for(j=1;j<=i;j++) {
			//j-2
			unsigned int c=j-1;
			D[i][j]=MOD+T[i-2][i-2]-T[i-2][c-1];
			D[i][j]%=MOD;
			D[i][j]+=D[i][j-1];
			D[i][j]%=MOD;
			T[i][j]=T[i][j-1]+D[i][j];
			T[i][j]%=MOD;
		}
	}
	printf("%u",D[n][n]);
}