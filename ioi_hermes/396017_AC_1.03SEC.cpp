#include<iostream>
#include<stdlib.h>
using namespace std;
int n;
int pos[20001][2];
int dp[2][2][2010];
int main() {
	int i,j;
	scanf("%d",&n);
	pos[0][0]=1001;
	pos[0][1]=1001;
	for(i=1;i<=n;i++) {
		scanf("%d%d",&pos[i][0],&pos[i][1]);
		pos[i][0]+=1001;
		pos[i][1]+=1001;
	}
	for(i=1;i<=2001;i++) {
		dp[0][0][i]=99999999;
		dp[0][1][i]=99999999;
		dp[1][0][i]=99999999;
		dp[1][1][i]=99999999;
	}
	dp[0][0][1001] = 0;
	dp[0][1][1001] = 0;
	for(i=1;i<=n;i++) {
		int g = i%2;
		int g2 = 1-g;
		for(j=1;j<=2001;j++) {
			if(dp[g2][0][j]+abs(pos[i-1][0]-pos[i][0]) < dp[g][0][j]) {
				dp[g][0][j]=dp[g2][0][j]+abs(pos[i-1][0]-pos[i][0]);
			}
			if(dp[g2][0][j]+abs(j-pos[i][1]) < dp[g][1][pos[i-1][0]]) {
				dp[g][1][pos[i-1][0]]=dp[g2][0][j]+abs(j-pos[i][1]);
			}
			dp[g2][0][j] = 99999999;
		}
		for(j=1;j<=2001;j++) {
			if(dp[g2][1][j]+abs(j-pos[i][0]) < dp[g][0][pos[i-1][1]]) {
				dp[g][0][pos[i-1][1]]=dp[g2][1][j]+abs(j-pos[i][0]);
			}
			if(dp[g2][1][j]+abs(pos[i-1][1]-pos[i][1]) < dp[g][1][j]) {
				dp[g][1][j]=dp[g2][1][j]+abs(pos[i-1][1]-pos[i][1]);
			}
			dp[g2][1][j] = 99999999;
		}

		for(j=1;j<=2001;j++)  {dp[g2][0][j]=99999999;dp[g2][1][j]=99999999;}
	}
	int mn=99999999;
	int g = n%2;
	for(i=1;i<=2000;i++) {
		if(dp[g][0][i] < mn) {
			mn = dp[g][0][i];
		}
		if(dp[g][1][i] < mn) {
			mn = dp[g][1][i];
		}
	}
	printf("%d",mn);
}