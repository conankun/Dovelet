#include<iostream>
using namespace std;
int dp[2000][2000][3];
int map[2000][2000];
int n;
int max(int a,int b) {
	if(a > b) return a;
	return b;
}
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			scanf("%d",&map[i][j]);
			dp[i][j][0]=-999999999;
			dp[i][j][1]=-999999999;
			dp[i][j][2]=-999999999;
		}
	}
	dp[1][1][1]=map[1][1];
	for(i=2;i<=n;i++) dp[1][i][1] = dp[1][i-1][1]+map[1][i];
	for(i=2;i<=n;i++) {
		for(j=1;j<=n;j++) {
			dp[i][j][0] = max(dp[i-1][j][0],max(dp[i-1][j][1],dp[i-1][j][2]))+map[i][j];
			if(j > 1) dp[i][j][1] = max(dp[i][j-1][0],dp[i][j-1][1])+map[i][j];
		}
		for(j=n-1;j>=1;j--) {
			dp[i][j][0] = max(dp[i-1][j][0],max(dp[i-1][j][1],dp[i-1][j][2]))+map[i][j];
			if(j < n) dp[i][j][2] = max(dp[i][j+1][0],dp[i][j+1][2])+map[i][j];
		}
	}  
	cout<<max(dp[n][n][0],max(dp[n][n][1],dp[n][n][2]));
}