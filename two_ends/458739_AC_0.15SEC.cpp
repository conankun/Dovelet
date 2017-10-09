#include<stdio.h>
int dp[2000][2000];
int point[2000];
int n,sum;
int max(int a,int b) {
	if(a>b) return a;
	return b;
}
int main() {
	scanf("%d",&n);
	int i,j,d;
	for(i=1;i<=n;i++) {
		scanf("%d",&point[i]);
		sum+=point[i];
	}
	for(i=1;i<=n-1;i++) {
		dp[i][i+1]=max(point[i],point[i+1]);
	}
	for(i=1;i<=n;i++) dp[i][i]=point[i];
	for(d=3;d<=n;d++) {
		for(i=1;i<=n-d+1;i++) {
			j=i+d-1;
			if(point[i+1] >= point[j]) {
				if(dp[i+2][j]+point[i] > dp[i][j]) dp[i][j] = dp[i+2][j]+point[i];
			} else {
				if(dp[i+1][j-1]+point[i] > dp[i][j]) dp[i][j] = dp[i+1][j-1]+point[i];
			}
			if(point[i] >= point[j-1]) {
				if(dp[i+1][j-1]+point[j] > dp[i][j]) dp[i][j]=dp[i+1][j-1]+point[j];
			} else {
				if(dp[i][j-2]+point[j] > dp[i][j]) dp[i][j]=dp[i][j-2]+point[j];
			}
		}
	}
	printf("the greedy strategy might lose by as many as %d points.",dp[1][n]-(sum-dp[1][n]));
}