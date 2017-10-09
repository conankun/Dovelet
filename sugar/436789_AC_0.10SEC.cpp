#include<iostream>
int dp[10000];
int n;
using namespace std;
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) dp[i]=-1;
	for(i=0;i<=n;i++) {
		if(dp[i] != -1) {
			if(dp[i+3]==-1) dp[i+3] = dp[i]+1;
			dp[i+3] = min(dp[i+3],dp[i]+1);
			if(dp[i+5]==-1) dp[i+5] = dp[i]+1;
			dp[i+5] = min(dp[i+5],dp[i]+1);
		}
	}
	printf("%d",dp[n]);
}