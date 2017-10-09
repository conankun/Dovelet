#include<stdio.h>
int honey[1000][1000];
int dp[3][1000][1000];
int maxhang[1000];
int size[1000];
int n;
int max(int a,int b) {
	if(a>b) return a;
	return b;
}
int main() {
	scanf("%d",&n);
	int cnt=n-1;
	int i,j;
	for(i=1;i<=n;i++) {
		cnt++;
		size[i]=cnt;
		for(j=1;j<=cnt;j++) {
			scanf("%d",&honey[i][j]);
			if(maxhang[i] < honey[i][j]) maxhang[i]=honey[i][j];
		}
	}
	for(i=n+1;i<=2*n-1;i++) {
		cnt--;
		size[i]=cnt;
		for(j=1;j<=cnt;j++) {
			scanf("%d",&honey[i][j]);
			if(maxhang[i] < honey[i][j]) maxhang[i]=honey[i][j];
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=size[i];j++) {
			dp[1][i][j] = max(dp[1][i-1][j],dp[1][i-1][j-1])+honey[i][j];
			dp[2][i][j] = max(max(dp[1][i-1][j],dp[1][i-1][j-1])+maxhang[i],max(dp[2][i-1][j],dp[2][i-1][j-1])+honey[i][j]);
		}
	}
	for(i=n+1;i<=2*n-1;i++) {
		for(j=1;j<=size[i];j++) {
			dp[1][i][j] = max(dp[1][i-1][j],dp[1][i-1][j+1])+honey[i][j];
			dp[2][i][j] = max(max(dp[1][i-1][j],dp[1][i-1][j+1])+maxhang[i],max(dp[2][i-1][j],dp[2][i-1][j+1])+honey[i][j]);
		}
	}
	int ans=0;
	for(j=1;j<=size[2*n-1];j++) {
		if(dp[2][2*n-1][j] > ans) ans = dp[2][2*n-1][j];
	}
	printf("%d",ans);
	return 0;
}