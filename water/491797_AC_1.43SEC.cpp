#include<stdio.h>
long long N;
long long water[1111111];
long long dp[1111111];
int main() {
	scanf("%lld",&N);
	int i;
	for(i=1;i<=N;i++) scanf("%lld",&water[i]);
	long long mx=0;
	for(i=1;i<=N;i++) {
		if(water[i-1]<water[i]) {
			dp[i]=dp[i-1]+water[i];
		} else dp[i]=water[i];
		if(dp[i] > mx) mx = dp[i];
	}
	printf("%lld",mx);
}