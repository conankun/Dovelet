#include<stdio.h>
long long max(long long a,long long b) {
	if(a>b) return a;
	return b;
}
long long arr[100001];
long long dp[100001];
long long n;
int main() {
	long long i;
	n=1;
	while(scanf("%lld",&arr[n])!=-1) {
		if(arr[n] != 0) n++;
	}
	long long ans=-2147483647000000;
	for(i=1;i<=n-1;i++) {
		dp[i] = max(dp[i-1]+arr[i],arr[i]);
		if(dp[i] > ans) ans = dp[i];
	}
	printf("%lld",ans);
}