#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n;
int rank[1000];
int mn[1000][1000];
int dp[1000][1000][2];//최소,경우의수
int min(int a,int b){if(a<b)return a;return b;}
int max(int a,int b){if(a>b)return a;return b;}
int main() {
	scanf("%d",&n);
	int i,j,k,d;
	for(i=1;i<=n;i++) scanf("%d",&rank[i]);
	for(i=1;i<=n;i++) {
		int mnss=rank[i];
		mn[i][i]=mnss;
		for(j=i+1;j<=n;j++) {
			if(mnss>rank[j]) mnss=rank[j];
			mn[i][j]=mnss;
		}
	}
	for(i=1;i<=n;i++) {
		dp[i][i][0]=0;
		dp[i][i][1]=1;
	}
	for(i=1;i<=n;i++) {
		dp[i][i+1][0]=max(rank[i],rank[i+1])-min(rank[i],rank[i+1]);
		dp[i][i+1][1]=1;
	}
	for(d=3;d<=n;d++) {
		for(i=1;i<=n-d+1;i++) {
			j=i+d-1;
			int s=0,mins=2147483647;
			for(k=i;k<=j-1;k++) {
				if(dp[i][k][0]+dp[k+1][j][0]+max(mn[i][k],mn[k+1][j])-min(mn[i][k],mn[k+1][j]) < mins) {
					s=0;
					mins=dp[i][k][0]+dp[k+1][j][0]+max(mn[i][k],mn[k+1][j])-min(mn[i][k],mn[k+1][j]);
					s+=dp[i][k][1]*dp[k+1][j][1];
				} else if(dp[i][k][0]+dp[k+1][j][0]+max(mn[i][k],mn[k+1][j])-min(mn[i][k],mn[k+1][j])==mins) {
					s+=dp[i][k][1]*dp[k+1][j][1];
				}
			}
			dp[i][j][0]=mins;
			dp[i][j][1]=s;
		}
	}
	printf("%d\n%d",dp[1][n][0],dp[1][n][1]);
}
