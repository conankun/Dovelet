#include<stdio.h>
#define MOD 1000000
int n;
int dp[1111111][3];//A,B,C
int main() {
	scanf("%d",&n);
	int i;
	dp[1][0]=1;
	dp[1][1]=1;
	dp[1][2]=1;
	for(i=2;i<=n-2;i++) {
		dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
		dp[i][0]%=MOD;
		dp[i][1]=dp[i-1][0];
		dp[i][1]%=MOD;
		dp[i][2]=dp[i-1][0];
		dp[i][1]%=MOD;
	}
	if(n==1) {
		printf("1");
	} else if(n==2) {
		printf("5");
	} else {
		//AA, BB,CC
		//AA 인경우 a,b,c에서 다받아올수
		//BB인 경우 A에서만 받아올수(cc도 마찬가지)
		int sum=dp[n-2][0]+dp[n-2][1]+dp[n-2][2];
		sum%=MOD;
		sum+=dp[n-2][0]*2;
		sum%=MOD;
		printf("%d",sum);
	}
}