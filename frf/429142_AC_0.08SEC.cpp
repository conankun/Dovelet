#include<stdio.h>
int dp[100][100][100];
int main() {
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a<0||b<0||c<0) {
		printf("w(%d, %d, %d) = 1",a,b,c);
		return 0;
	}
	int i,j,k;
	for(i=0;i<=20;i++) for(j=0;j<=20;j++) for(k=0;k<=20;k++) if(i==0||j==0||k==0) dp[i][j][k]=1;
	for(i=1;i<=20;i++) {
		for(j=1;j<=20;j++) {
			for(k=1;k<=20;k++) {
				if(i < j && j < k) dp[i][j][k] = dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k];
				else dp[i][j][k] = dp[i-1][j][k]+dp[i-1][j-1][k]+dp[i-1][j][k-1]-dp[i-1][j-1][k-1];
			}
		}
	}
	if(a>20||b>20||c>20) {
		printf("w(%d, %d, %d) = %d",a,b,c,dp[20][20][20]);
		return 0;
	} else 
	printf("w(%d, %d, %d) = %d",a,b,c,dp[a][b][c]);
}