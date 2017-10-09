#include<iostream>
using namespace std;
int puz[1000];
int dp[1000][1000];
int n;
int main() {
	scanf("%d",&n);
	int d,i,j,k;
	for(i=1;i<=n;i++) scanf("%d",&puz[i]);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) dp[i][j]=99999999;
	for(i=1;i<=n-2;i++) {
		dp[i][i+2] = puz[i]*puz[i+1]*puz[i+2];
	}
	for(d=4;d<=n;d++) {
		for(i=1;i<=n-d+1;i++) {
			j = i+d-1;
			dp[i][j] = min(dp[i][j-1]+puz[i]*puz[j-1]*puz[j],dp[i+1][j]+puz[i]*puz[j]*puz[i+1]);
		}
	}
	printf("%d",dp[1][n]);
}