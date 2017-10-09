#include<stdio.h>
int n,a,b,T;
int order[100];
int ans=99999999;
int dp[100][100][100];
int min(int a,int b) {
	if(a<b) return a;
	return b;
}
int main() {
	int i,j,k;
	scanf("%d%d%d",&n,&a,&b);
	if(a>b) {
		int temp = a;
		a = b;
		b = temp;
	}
	scanf("%d",&T);
	for(i=1;i<=T;i++) {
		scanf("%d",&order[i]);
	}
	for(i=0;i<100;i++) for(j=0;j<100;j++) for(k=0;k<100;k++) dp[i][j][k]=99999999;
	dp[0][a][b]=0;
	for(k=1;k<=T;k++) {
		if(k==1) {
			for(i=1;i<=n;i++) {
				for(j=1;j<=n;j++) {
					if(i>1) dp[k][i-1][j] = min(dp[k][i-1][j],dp[k-1][i][j]+1);
					if(i<n && i+1 < j) dp[k][i+1][j] = min(dp[k][i+1][j],dp[k-1][i][j]+1);
					if(j>1 && j-1 > i) dp[k][i][j-1] = min(dp[k][i][j-1],dp[k-1][i][j]+1);
					if(j<n) dp[k][i][j+1] = min(dp[k][i][j+1],dp[k-1][i][j]+1);
					dp[k][i][j] = min(dp[k][i][j],dp[k-1][i][j]);
				}
			}
		} else {
			//dp[order[k-1]][j]
			//dp[i][order[k-1]]
			for(i=order[k-1];i<=n;i++) {
				if(i != order[k-1]) {
					if(i-1 > order[k-1]) dp[k][order[k-1]][i-1] = min(dp[k][order[k-1]][i-1],dp[k-1][order[k-1]][i]+1);
					if(i+1 <= n) dp[k][order[k-1]][i+1] = min(dp[k][order[k-1]][i+1],dp[k-1][order[k-1]][i]+1);
					dp[k][order[k-1]-1][i] = min(dp[k][order[k-1]-1][i],dp[k-1][order[k-1]][i]+1);
					if(order[k-1]+1 < i) dp[k][order[k-1]+1][i] = min(dp[k][order[k-1]+1][i],dp[k-1][order[k-1]][i]+1);
				}
				dp[k][order[k-1]][i] = min(dp[k][order[k-1]][i],dp[k-1][order[k-1]][i]);
			}
			for(i=1;i<=order[k-1];i++) {
				if(i != order[k-1]) {
					dp[k][i-1][order[k-1]] = min(dp[k][i-1][order[k-1]],dp[k-1][i][order[k-1]]+1);
					if(i+1 < order[k-1]) dp[k][i+1][order[k-1]] = min(dp[k][i+1][order[k-1]],dp[k-1][i][order[k-1]]+1);
					if(order[k-1]-1 > i) dp[k][i][order[k-1]-1] = min(dp[k][i][order[k-1]-1],dp[k-1][i][order[k-1]]+1);
					if(order[k-1]+1 <= n) dp[k][i][order[k-1]+1] = min(dp[k][i][order[k-1]+1],dp[k-1][i][order[k-1]]+1);
				}
				dp[k][i][order[k-1]] = min(dp[k][i][order[k-1]],dp[k-1][i][order[k-1]]);
			}
		}
		for(i=1;i<=n;i++) {
			for(j=1;j<=n;j++) {
				if(i>1) dp[k][i-1][j] = min(dp[k][i-1][j],dp[k][i][j]+1);
				if(i<n && i+1 < j) dp[k][i+1][j] = min(dp[k][i+1][j],dp[k][i][j]+1);
				if(j>1 && j-1 > i) dp[k][i][j-1] = min(dp[k][i][j-1],dp[k][i][j]+1);
				if(j<n) dp[k][i][j+1] = min(dp[k][i][j+1],dp[k][i][j]+1);
			}
		}
		dp[k][i][order[k]] = min(dp[k][i][order[k]],min(dp[k][i][order[k]-1],dp[k][i][order[k]+1]));
		dp[k][order[k]][j] = min(dp[k][order[k]][j],min(dp[k][order[k]-1][j],dp[k][order[k]+1][j]));
	}
	int ans=99999999;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(i==order[T] || j == order[T]) ans = min(ans,dp[T][i][j]); 
	printf("%d",ans);
}