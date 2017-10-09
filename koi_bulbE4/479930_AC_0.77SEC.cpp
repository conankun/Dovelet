#include<stdio.h>
int dp[21][201][201],N,K,color[999],c[999],m,mi[201][201];
int min(int aa,int bb) {
	if(aa<bb) return aa;
	return bb;
}
int main() {
	scanf("%d%d",&N,&K);
	int i,j,k,d,l;
	for(k=1;k<=K;k++) for(i=1;i<=N;i++) for(j=1;j<=N;j++) dp[k][i][j]=99999999;
	for(i=1;i<=N;i++) for(j=i+1;j<=N;j++) mi[i][j]=999999999;
	for(i=1;i<=N;i++) {
		scanf("%d",&color[i]);
		if(color[i] != color[i-1]) {
			m++;
			c[m]=color[i];
			for(k=1;k<=K;k++) {
				if(k==c[m]) dp[k][m][m]=0;
				else dp[k][m][m]=1;
			}
		}
	}
	N=m;
	for(d=2;d<=N;d++) {
		for(k=1;k<=K;k++) {
			for(i=1;i<=N-d+1;i++) {
				j=i+d-1;
				dp[k][i][j]=99999999;
				for(l=1;l<=j-1;l++) {
					if(min(mi[i][l]+1,dp[k][i][l])+min(mi[l+1][j]+1,dp[k][l+1][j]) < dp[k][i][j]) dp[k][i][j] = min(mi[i][l]+1,dp[k][i][l])+min(mi[l+1][j]+1,dp[k][l+1][j]);
				}
				if(dp[k][i][i]+dp[k][j][j]+min(mi[i+1][j-1]+1,dp[k][i+1][j-1]) < dp[k][i][j]) dp[k][i][j] = dp[k][i][i]+dp[k][j][j]+min(mi[i+1][j-1]+1,dp[k][i+1][j-1]);
				if(dp[k][i][j] < mi[i][j]) mi[i][j]=dp[k][i][j];
			}
		}
	}
	int ans=99999999;
	for(k=1;k<=K;k++) if(ans > dp[k][1][N]) ans = dp[k][1][N];
	printf("%d",ans);
}