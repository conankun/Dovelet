#include<iostream>
using namespace std;
int k,n;
int dp[1000][1000];
int sum[1000][1000];
int main() {
	cin>>k>>n;
	int i,j,z;
	for(i=0;i<=k;i++) dp[1][i] = 1;
	for(i=2;i<=n;i++) {
		for(j=0;j<=k;j++) {
			if(j-1 >= 0) dp[i][j]+=dp[i-1][j-1];
			if(j+1 <= k) dp[i][j]+=dp[i-1][j+1];
			dp[i][j]+=dp[i-1][j];
		}
	}
	for(i=0;i<=k;i++) sum[1][i] = 1;
	for(i=2;i<=n;i++) {
		for(j=0;j<=k;j++) {
			for(z=0;z<=k;z++) sum[i][j]+=sum[i-1][z];
		}
	}
	int sum1=0;
	int sum2=0;
	for(i=0;i<=k;i++) sum1+=dp[n][i];
	for(i=0;i<=k;i++) sum2+=sum[n][i];
	printf("%.5f",(sum1/(double)sum2)*100);
}