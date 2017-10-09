#include<stdio.h>
int dp[2000][1000];
int M,N;
int cnt;
struct A {
	int len,cost;
}train[10000];
int main() {
	int a,b,c;
	scanf("%d%d",&M,&N);
	int i,j;
	for(i=1;i<=N;i++) {
		scanf("%d%d%d",&a,&b,&c);
		for(j=1;j<=c;j++) {
			train[++cnt].len = a;
			train[cnt].cost = b;
		}
	}
	for(i=1;i<=cnt;i++) {
		for(j=1;j<=M;j++) {
			dp[i][j]=-1;
		}
	}
	dp[1][train[1].len]=train[1].cost;
	for(i=2;i<=cnt;i++) {
		for(j=0;j<=M;j++) {
			if(dp[i-1][j] != -1 && (dp[i][j+train[i].len] > train[i].cost+dp[i-1][j] || dp[i][j+train[i].len] == -1)) {
				dp[i][j+train[i].len] = train[i].cost+dp[i-1][j];
			}
			if((dp[i][j] > dp[i-1][j] || dp[i][j] == -1) && dp[i-1][j] != -1) dp[i][j] = dp[i-1][j];
		}
	}
	int ans=-1;
	for(i=1;i<=cnt;i++) {
		if(ans == -1 || dp[i][M] < ans) ans = dp[i][M];
	}
	printf("%d",ans);
}