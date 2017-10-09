#include<stdio.h>
#define MOD 1000000009
long long n,D[5111][5111],T[5111][5111];
int main() {
	scanf("%lld",&n);
	long long i,j;
	T[1][1]=1;T[2][1]=1;T[2][2]=2;
	for(i=3;i<=n;i++) {
		for(j=1;j<=i;j++) {
			//j-2
			long long c=j-1;
			D[i][j]=T[i-2][i-2]-T[i-2][c-1];
			D[i][j]%=MOD;
			D[i][j]+=D[i][j-1];
			D[i][j]%=MOD;
			T[i][j]=T[i][j-1]+D[i][j];
			T[i][j]%=MOD;
		}
	}
	printf("%lld",D[n][n]);
}