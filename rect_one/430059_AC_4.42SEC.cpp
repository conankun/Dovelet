#include<stdio.h>
int n;
int dp[10000001];
int main() {
	int i;
	dp[1]=1;
	dp[2]=5;
	for(i=3;i<=10000000;i++) {
		dp[i]+=(i%1000)*(i%1000);
		dp[i]+=dp[i-1];
		dp[i]%=1000;
	}
	while(scanf("%d",&n) != -1) {
		printf("%d\n",dp[n]);
	}
}