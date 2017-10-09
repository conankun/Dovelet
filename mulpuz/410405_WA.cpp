#include<iostream>
using namespace std;
int puz[1000];
int dp[1000][1000];
int n;
int main() {
	scanf("%d",&n);
	int d,i,j,k;
	for(i=1;i<=n;i++) scanf("%d",&puz[i]);
	//for(i=1;i<=n;i++) for(j=1;j<=n;j++) dp[i][j]=99999999;
	for(i=2;i<=n-1;i++) {
		dp[i][i] = puz[i]*puz[i-1]*puz[i+1];
	}
	for(d=2;d<=n;d++) {
		for(i=1;i<=n-d+1;i++) {
			j = i+d-1;
			if(i!=1&&j!=n) dp[i][j] = min(dp[i][j-1]+puz[j]*puz[j+1]*puz[i-1],dp[i+1][j]+puz[i]*puz[i-1]*puz[j+1]);
			if(i!=1&&j==n) dp[i][j] = dp[i+1][j]+puz[i]*puz[i-1]*puz[j+1];
			if(i==1&&j!=n) dp[i][j] = dp[i][j-1]+puz[j]*puz[j+1]*puz[i-1];
			for(k=i+1;k<=j;k++) {
				if(dp[i][k]+dp[k+1][j] < dp[i][j]) dp[i][j] = dp[i][k]+dp[k+1][j];
			}
		}
	}
	printf("%d",dp[2][n-1]);
}